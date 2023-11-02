/* Note to self:
when compiling, ensure that you use the command:
    g++ *.cpp -o "[file name]"
so that all cpp files can be included in the compilation.
*/

#include <iostream>
#include "SparseMatrix.hpp"


using namespace std;

int main() {
    int r[4] = {0, 1, 2, 3};
    int c[4] = {3, 2, 1, 0};
    int v[4] = {3, 1, 4, 1};
    int s = 4; 

    SparseMatrix* hi = new SparseMatrix(r, c, v, s);
    hi->printElements();

    delete hi;
}