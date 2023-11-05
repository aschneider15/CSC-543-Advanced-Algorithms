#include "SparseMatrix.hpp"

// constructor and destructor
SparseMatrix::SparseMatrix(int* row, int* column, int* value, int size, int width, int height) {
    this->row = row;
    this->column = column;
    this->value = value;
    this->size = size;
    this->width = width;
    this->height = height;
}

SparseMatrix::~SparseMatrix() {
    delete[] this->row;
    delete[] this->column;
    delete[] this->value;
}


// helper functions
void SparseMatrix::printComprisingArrays() {
    // print contents of row array
    printf("[");
    for(int i = 0; i < this->size; i++) {
        if(i != this->size -1) {
            printf(" %d, ", this->row[i]);
        } else {
            printf(" %d ", this->row[i]);
        }
    }
    printf("]\n");

    // print contents of column array
    printf("[");
    for(int i = 0; i < this->size; i++) {
        if(i != this->size -1) {
            printf(" %d, ", this->column[i]);
        } else {
            printf(" %d ", this->column[i]);
        }
    }
    printf("]\n");

    // print contents of value array
    printf("[");
    for(int i = 0; i < this->size; i++) {
        if(i != this->size -1) {
            printf(" %d, ", this->value[i]);
        } else {
            printf(" %d ", this->value[i]);
        }
    }
    printf("]\n");
}

void SparseMatrix::printMatrix() {
    // Shorthand. I don't feel like writing out "this->row" or whatever every time
    int* r = this->row;
    int* c = this->column;
    int* v = this->value;
    int w = this->width;
    int h = this->height;

    int rpos, cpos, vpos; //keep track of positions while searching through each array
    rpos = cpos = vpos = 0; //i initialize at position 0
    int mat[h][w];

    /*
        Create a matrix of size (height x width) full of zeroes.
        Go through the row, column and value arrays, altering
        each coordinate in the first two arrays with the value
        of the third array.
    */
   
    // fill the matrix with all zeroes
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            mat[i][j] = 0;
        }
    }

    // replace values from comprising arrays
    for(int i = 0; i < this->size; i++) {
        mat[r[i]][c[i]] = v[i];
    }

    // display resulting matrix
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            printf("%d ", mat[i][j]);
        }
        // seperate row with new line
        printf("\n");
    }
}