#include "SHa.hpp"

using namespace std;

SHa::SHa(const char * input, uint64_t length) {
    this->length = length;
    cout << "Concatenating bits of the original string into 32-bit words." << endl;
    concatenateBits(input);
    cout << "Populating chunks using concatenated words." << endl;
    populateChunks();
    cout << "Generating message schedule using 512-bit chunks." << endl;
    createMessageSchedule();
    cout << "Compressing and hashing message schedule:" << endl;
    compress();

    for(int i = 0; i < 8; i++) {
        std::cout << std::hex << std::setw(8) << std::setfill('0') << this->hashInit[i] << " ";
    }
    std::cout << std::endl; 
};

void SHa::concatenateBits(const char* charArray) {
    // Calculate the number of characters needed for padding
    uint64_t padding = 4 - (this->length % 4);

    // If perfectly divisible by 4, no padding needed
    if (padding == 4) {
        padding = 0;
    }

    // Calculate the padded length
    uint64_t paddedLength = this->length + padding;
    cout << "\tTotal length (padding included) = " << paddedLength << endl;

    // Iterate over the input string with a step of 4 characters
    for (size_t i = 0; i < paddedLength; i += 4) {
        uint32_t word = 0;

        // Convert 4 characters at a time into a 32-bit word
        for (size_t j = 0; j < 4; ++j) {
            word <<= 8;
            if ((i + j) < this->length) {
                word |= static_cast<uint8_t>(charArray[i + j]);
            }
        }

        // If padding is needed and it's the last word, append 1 and pad with 0s
        if (padding > 0 && (i + 3) >= this->length) {
            if (padding == 1) {
                // Append 1 at the end of the last byte
                word |= 0x00000080;
            }
            else if (padding == 2) {
                // Append 1 at the end of the second last byte
                word |= 0x00008000;
            }
            else if (padding == 3) {
                // Append 1 at the end of the third last byte
                word |= 0x00800000;
            }
        }

        // Push the 32-bit word into the queue
        this->words.push(word);
    }

    // If the input length is fully divisible by 4, push an additional word with 0x80000000
    if (padding == 0) {
        this->words.push(0x80000000);
    }
};

void SHa::populateChunks() {
    // Create temporary chunk buffer
    std::vector<uint32_t> chunk(16);

    // While there are still words to offload
    while (!this->words.empty()) {

        for (int i = 0; i < 16; i++) {

            // Second check
            if (!this->words.empty()) {
                chunk[i] = this->words.front();
                this->words.pop();
            }
            else {

                // If no more words to offload, then append zeroes until the last two words,
                // which will represent the length of the input.
                if (i < 14) {
                    chunk[i] = 0;
                }
                else if (i == 14) {
                    chunk[i] = static_cast<uint32_t>(this->length * 8 >> 32);
                }
                else {
                    chunk[i] = static_cast<uint32_t>(this->length * 8);
                }
            }
        }

        // Add the new chunk to the chunks vector
        this->chunks.push(chunk);
    }
};

void SHa::createMessageSchedule() {
    // Create temp strctures
    std::array<uint32_t, 64> message;
    std::vector<uint32_t> chunk(16);


    // Initialize the first message schedule as all zeros
    for(uint32_t word : message) {
        word = 0x00000000;
    }
    
    // Copy chunk into first 16 words w[0..15] of the message schedule array
    while(! this->chunks.empty()) {
        // Put the front of the chunks queue into the temp variable
        chunk = this->chunks.front();
        this->chunks.pop();

        // Populate the message schedule array using the chunk
        for(int i = 0; i < 64; i++) {
            // Copy chunk into first 16 words w[0..15] of the message schedule array
            if(i < 16) {
                message.at(i) = chunk.at(i);
            
            // Utilitze the sigma functions to derive 16-63: w[i] := w[i-16] + s0 + w[i-7] + s1
            } else {
                // I think this would count as addition modulo 2^32 since it's being stored in an unsigned 32-bit int...
                // But if there are problems, let's return to this line to figure something out.
                message.at(i) = (message.at(i - 16) + sigmaZero(message.at(i - 15)) + message.at(i - 7) + sigmaOne(message.at(i - 2)));
            }
        }
        // Add message to the end of the message schedule
        this->messageSchedule.push_back(message);
    }


};

uint32_t * SHa::compress() {
    // Initialize the working variables
    uint32_t a = this->hashInit[0];
    uint32_t b = this->hashInit[1];
    uint32_t c = this->hashInit[2];
    uint32_t d = this->hashInit[3];
    uint32_t e = this->hashInit[4];
    uint32_t f = this->hashInit[5];
    uint32_t g = this->hashInit[6];
    uint32_t h = this->hashInit[7];

    // temp variable to hold current message
    std::array<uint32_t, 64> message;

    // Repeat until there are no message left to be processed
    while(!this->messageSchedule.empty()) {
        // Initialize the working variables
        uint32_t a = this->hashInit[0];
        uint32_t b = this->hashInit[1];
        uint32_t c = this->hashInit[2];
        uint32_t d = this->hashInit[3];
        uint32_t e = this->hashInit[4];
        uint32_t f = this->hashInit[5];
        uint32_t g = this->hashInit[6];
        uint32_t h = this->hashInit[7];

        // temp variable to hold current message
        std::array<uint32_t, 64> message;
        message = this->messageSchedule.front();

        // temp variables to hold the sums of compression helper functions
        uint32_t temp1;
        uint32_t temp2;

        // iterate throught the whole message word by word
        for(int i = 0; i < 64; i++) {
            temp1 = h + capSigmaOne(e) + choose(e, f, g) + this->roundInit[i] + message.at(i);
            temp2 = capSigmaZero(a) + majority(a, b, c);

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Add the compressed chunk to the current hash value:
        this->hashInit[0] = this->hashInit[0] + a;
        this->hashInit[1] = this->hashInit[1] + b;
        this->hashInit[2] = this->hashInit[2] + c;
        this->hashInit[3] = this->hashInit[3] + d;
        this->hashInit[4] = this->hashInit[4] + e;
        this->hashInit[5] = this->hashInit[5] + f;
        this->hashInit[6] = this->hashInit[6] + g;
        this->hashInit[7] = this->hashInit[7] + h;

        // remove the front message from the schedule
        this->messageSchedule.erase(this->messageSchedule.begin());
    }

    // Produce the final hash result
    uint32_t output[8];

    for (size_t i = 0; i < 8; i++) {
        output[i] = this->hashInit[i];
    }

    return output;
};

uint32_t SHa::sigmaZero(uint32_t input) {
    uint32_t output = input;
    uint32_t temp = input;

    // Right rotate the input by 7 bits
    temp = (temp >> 7) | (temp << (32 - 7));
    // XOR with right rotated input by 18 bits
    temp ^= (input >> 18) | (input << (32 - 18));
    // XOR with right shifted input by 3 bits
    temp ^= input >> 3;

    output = temp;
    return output;
};

// w[i-2] rightrotate 17) xor (w[i-2] rightrotate 19) xor (w[i-2] rightshift 10
uint32_t SHa::sigmaOne(uint32_t input) {
    uint32_t output = input;
    uint32_t temp = input;

    // Right rotate the input by 17 bits
    temp = (temp >> 17) | (temp << (32 - 17));
    // XOR with right rotated input by 18 bits
    temp ^= (input >> 19) | (input << (32 - 19));
    // XOR with right shifted input by 3 bits
    temp ^= input >> 10;

    output = temp;
    return output;
}; 

// (a rightrotate 2) xor (a rightrotate 13) xor (a rightrotate 22)
uint32_t SHa::capSigmaZero(uint32_t input) {
    uint32_t output = input;
    uint32_t temp = input;

    // Right rotate the input by 2 bits
    temp = (temp >> 2) | (temp << (32 - 2));
    // XOR with right rotated input by 13 bits
    temp ^= (input >> 13) | (input << (32 - 13));
    // XOR with right rotated input by 22 bits
    temp ^= (input >> 22) | (input << (32 - 22));

    output = temp;
    return output;
};

// (e rightrotate 6) xor (e rightrotate 11) xor (e rightrotate 25)
uint32_t SHa::capSigmaOne(uint32_t input) {
    uint32_t output = input;
    uint32_t temp = input;

    // Right rotate the input by 6 bits
    temp = (temp >> 6) | (temp << (32 - 6));
    // XOR with right rotated input by 11 bits
    temp ^= (input >> 11) | (input << (32 - 11));
    // XOR with right rotated input by 25 bits
    temp ^= (input >> 25) | (input << (32 - 25));

    output = temp;
    return output;
};

// (e and f) xor ((not e) and g)
uint32_t SHa::choose(uint32_t e, uint32_t f, uint32_t g) {
    return ((e & f) ^ ((~e) & g));
};

// (a and b) xor (a and c) xor (b and c)
uint32_t SHa::majority(uint32_t a, uint32_t b, uint32_t c) {
    return ((a & b) ^ (a & c) ^ (b & c));
};