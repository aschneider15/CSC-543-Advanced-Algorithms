#include "table.hpp"
#include <iostream>

table::table(std::string s1, std::string s2) {
    // create the matrix
    // row size is s1 size, column size is s2 size.
    this->s1 = s1;
    this->s2 = s2;
    this->rowsize = s1.size();
    this->colsize = s2.size();
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
}

int table::getValueAt(int row, int col) {
    return this->mat[row][col];
};

void table::printMatrix() {
    for(int i = 0; i < this->rowsize; i++) {
        for(int j = 0; j < this->colsize; j++) {
            std::cout << this->mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}