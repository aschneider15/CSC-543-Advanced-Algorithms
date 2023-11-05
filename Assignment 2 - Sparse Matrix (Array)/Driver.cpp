/* Note to self:
when compiling, ensure that you use the command:
    g++ *.cpp -o "[file name]"
so that all cpp files can be included in the compilation.
*/

#include <iostream>
#include "SparseMatrix.hpp"


using namespace std;

int main() {
    int s, h, w;
    cout << "How many points would you like to plot in the matrix? >";
    cin >> s;
    cout << "What is the height resitriction? >";
    cin >> h;
    if(h <= 0) {
        cout << "ERROR: CANNOT HAVE NONPOSITIVE HEIGHT!";
        return 1;
    }
    cout << "What is the width resitriction? >";
    cin >> w;
    if(w <= 0) {
        cout << "ERROR: CANNOT HAVE NONPOSITIVE WIDTH!";
        return 1;
    }
    
    // create three arrays of size s
    int r[s]; // row
    int c[s]; // column
    int v[s]; // value

    for(int i = 0; i < s; i++) { // prompt user for values
        cout << "Enter row position for point " << i + 1 << " >";
        cin >> r[i];
        if(r[i] >= h || r[i] < 0) {
            cout << "ERROR: OUT OF WIDTH BOUNDS!";
            return 1;
        }

        cout << "Enter column position for point " << i + 1 << " >";
        cin >> c[i];
        if(c[i] >= w || c[i] < 0) {
            cout << "ERROR: OUT OF WIDTH BOUNDS!";
            return 1;
        }

        cout << "Enter value for point " << i + 1 << " >";
        cin >> v[i];
        if(v[i] <= 0) {
            cout << "ERROR: CANNOT ENTER NONPOSITIVE OR NONZERO!";
            return 1;
        }
    }
    
    // create new sparse matrix given the provided data.
    SparseMatrix* hi = new SparseMatrix(r, c, v, s, w, h);

    cout << "================================================" << endl;
    hi->printMatrix();
    cout << "================================================" << endl;
    hi->printComprisingArrays();

    delete hi;
    return 0;
}