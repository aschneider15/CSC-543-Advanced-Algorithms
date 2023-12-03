#include "HuffmanTree.hpp"

HuffmanTree::HuffmanTree(const std::unordered_map<char, int> & frequencyTable) {
    buildMinHeap();
    while(this->minHeap.size() > 1) {
        // create pairs of leaves, then create
        // intermideary nodes which have a frequency
        // which is the sum of the two leaves
        HNode * left = minHeap.top();
        minHeap.pop();

        HNode * right = minHeap.top();
        minHeap.pop();

        HNode * sumNode = new HNode;
        sumNode->info = NULL; // no "info" on connective nodes
        sumNode->frequency = left->frequency + right->frequency;
        sumNode->llink = left;
        sumNode->rlink = right;
    }
    // the final node in the minheap is the root of the tree.
    this->root = minHeap.top();
}

void HuffmanTree::buildMinHeap() {
    for(const std::pair<const char, int> & entry : this->frequencyTable) {
        HNode * newNode = new HNode;
        newNode->info = entry.first;
        newNode->frequency = entry.second;
        this->minHeap.push(newNode);
    }
}

void HuffmanTree::generateHuffmanCodes(HNode * curNode, const std::string & code, std::unordered_map<char, std::string> & huffmanCodes) {
    // base case
    if(curNode == nullptr) {
        return;
    }

    if(curNode->info != NULL) {
        huffmanCodes[curNode->info] = code;
    }

    generateHuffmanCodes(curNode->llink, code + "0", huffmanCodes);
    generateHuffmanCodes(curNode->rlink, code + "0", huffmanCodes);
}

std::unordered_map<char, std::string> HuffmanTree::getHuffmanCode() {
    std::unordered_map<char, std::string> huffmanCodes;
    generateHuffmanCodes(this->root, "", huffmanCodes);
    return huffmanCodes;
}