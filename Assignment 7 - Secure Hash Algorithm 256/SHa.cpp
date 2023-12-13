#include "SHa.hpp"

SHa::SHa(char * input, uint64_t length) {
    this->length = length;
    concatenateBits(input);
    populateChunks();
    /* 
        for(std::vector<uint32_t> v : this->chunks) {
            for(uint32_t word : v) {
                std::cout << std::bitset<32>(word) << std::endl;
            }
            std::cout << std::endl;
        } 
    */
};

void SHa::concatenateBits(char* charArray) {
    // Calculate the number of characters needed for padding
    uint64_t padding = 4 - (this->length % 4);
    // If perfectly divisible by 4, no padding needed
    if (padding == 4) {
        padding = 0;
    }

    // Calculate the padded length
    uint64_t paddedLength = this->length + padding;

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
                    chunk[i] = static_cast<uint32_t>(this->length >> 32);
                }
                else {
                    chunk[i] = static_cast<uint32_t>(this->length);
                }
            }
        }

        // add the new chunk to the chunks vector
        this->chunks.push_back(chunk);
    }
};
