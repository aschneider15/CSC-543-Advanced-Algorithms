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
    int width;
    int height;

public:
    // constructor and destructor
    SparseMatrix(int* row, int* column, int* value, int size, int width, int height);
    ~SparseMatrix();
    
    // getters
    int* getRow() { return this->row; };
    int* getColumn() { return this->column; };
    int* getValue() { return this->value; };
    int getSize() { return this-> size; };
    int getWidth() { return this->width; };
    int getHeight() { return this->height; };

    // helper functions
    void printComprisingArrays();
    void printMatrix();
};

#endif