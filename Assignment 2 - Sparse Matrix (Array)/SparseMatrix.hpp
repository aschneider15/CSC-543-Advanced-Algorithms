#ifndef SPARSEMATRIX_HPP
#define SPARSEMATRIX_HPP

#include <stdlib.h>
#include <stdio.h>

class SparseMatrix {
private:
    int* row;
    int* column;
    int* value;
    int size;

public:
    // constructor
    SparseMatrix(int* row, int* column, int* value, int size);
    
    // getters
    int* getRow() { return this->row; };
    int* getColumn() { return this->column; };
    int* getValue() { return this->value; };
    int getSize() { return this->size; };


    void printElements();
};

#endif