#include "table.hpp"
#include <iostream>

table::table(std::string s1, std::string s2) {
    // create the matrix
    // row size is s1 size, column size is s2 size.
    this->s1 = s1;
    this->s2 = s2;
    this->rowsize = s1.size() + 1;
    this->colsize = s2.size() + 1;
    this->mat = new int * [this->rowsize];
    for(int i = 0; i < this->rowsize; i++) {
        this->mat[i] = new int[this->colsize];
    }
    
    // initialize all values as zero
    for(int i = 0; i < this->rowsize; i++) {
        for(int j = 0; j < this->colsize; j++) {
            this->mat[i][j] = 0;
        }
    }
};

table::~table() {
    // deallocate matrix
    for(int i = 0; i < this->rowsize; i++) {
        delete[] mat[i];
    }
    delete[] mat;
};

int table::getValueAt(int row, int col) {
    return this->mat[row][col];
};

void table::setValueAt(int row, int col, int val) {
    this->mat[row][col] = val;
    return;
};

void table::printMatrix() {
    for(int i = 0; i < this->rowsize; i++) {
        for(int j = 0; j < this->colsize; j++) {
            std::cout << this->mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
};

std::string table::longestCommonSubstring() {
    int maxLen = 0;
    int endIndex = 0;
    // have to start at 1,1 in order to compensate for the 
    // edges of the table inherent to the problem.
    for(int i = 1; i < this->rowsize; i++) {
        for(int j = 1; j < this->colsize; j++) {
            // if the characters at the given index are the same,
            // then poll the previous row and column's value
            // and add one to it.
            if(this->s2.at(j-1) == this->s1.at(i-1)) {
                this->mat[i][j] = this->mat[i - 1][j - 1] + 1;
                if(this->mat[i][j] > maxLen) {
                    maxLen = this->mat[i][j];
                    endIndex = j;
                }
            }
        }
    }
    std::string output = s2.substr( endIndex - maxLen, maxLen);
    return output;

};