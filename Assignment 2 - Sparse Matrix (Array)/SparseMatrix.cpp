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

    /* 
    Go through nested for-loops
    If row[current position] = outer loop position AND column[current position] = inner loop position
        Print the value at those coordinates, followed by a space
        Then advance all of the row, column, value positions.
    Otherwise, print a a zero.
     */
    for(int i = 0; i < h; i++) { // iterates through rows
        for(int j = 0; j < w; j++) { // iterates through columns
            if(r[rpos] == i && c[cpos] == j) {
                printf("%d ", v[vpos]);
                rpos++;
                cpos++;
                vpos++;
            } else {
                printf("0 "); // blank - no value
            }
        }
        printf("\n"); // new line after each row completes
    }
}