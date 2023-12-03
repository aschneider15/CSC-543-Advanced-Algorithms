#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP

#include <iostream>
#include <unordered_map>
#include <queue>
#include "BinaryTree.hpp"


class HuffmanTree : BinaryTree {
    // had to superimpose the new llink and rlink
    // because I was encountering compatibility problems
    // in the generateHuffmanCodes function
    struct HNode : public Node{
        int frequency;
        HNode * llink;
        HNode * rlink;
    };


    private:
        // had to superimpose root for similar reasons
        // as above.
        HNode * root;
        struct CompareNodes {
            bool operator()(HNode * a, HNode * b) {
                return a->frequency > b->frequency;
            }
        };
        std::unordered_map<char, int> frequencyTable;
        void buildMinHeap();
        std::priority_queue<HNode *, std::vector<HNode *>, CompareNodes> minHeap;

        // recursive function to generate the bitstream representing
        // the path taken through the Huffman Tree
        void generateHuffmanCodes(HNode * curNode, const std::string & code, std::unordered_map<char, std::string> & huffmanCodes);
    protected:
    public:
        // create priority queue from unordered map
        HuffmanTree(const std::unordered_map<char, int> & frequencyTable);
        std::unordered_map<char, std::string> getHuffmanCode();
        
};

#endif