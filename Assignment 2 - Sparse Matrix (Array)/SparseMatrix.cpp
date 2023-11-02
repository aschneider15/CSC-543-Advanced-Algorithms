#include "SparseMatrix.hpp"

SparseMatrix::SparseMatrix(int* row, int* column, int* value, int size) {
    this->row = row;
    this->column = column;
    this->value = value;
    this->size = size;
}

void SparseMatrix::printElements() {
    // Shorthand. I don't feel like writing out "this->row" or whatever every time
    int* r = this->row;
    int* c = this->column;
    int* v = this->value;
    int s = this->size;

    int rpos, cpos, vpos; //keep track of positions while searching through each array
    rpos = cpos = vpos = 0; //i initialize at position 0

    /* 
    Go through nested for-loops
    If row[current position] = outer loop position AND column[current position] = inner loop position
        Print the value at those coordinates, followed by a space
        Then advance all of the row, column, value positions.
    Otherwise, print a blank space (or a zero? haven't decided yet).
     */
    for(int i = 0; i < s; i++) { // iterates through rows
        for(int j = 0; j < s; j++) { // iterates through columns
            if(r[rpos] == i && c[cpos] == j) {
                printf("%d ", v[vpos]);
                rpos++;
                cpos++;
                vpos++;
            } else {
                printf("  "); // blank - no value
            }
        }
        printf("\n"); // new line after each row completes
    }
}