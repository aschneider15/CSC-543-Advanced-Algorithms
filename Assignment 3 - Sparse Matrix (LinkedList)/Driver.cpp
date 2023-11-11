/* Note to self:
when compiling, ensure that you use the command:
    g++ *.cpp -o "[file name]"
so that all cpp files can be included in the compilation.
*/

#include <iostream>
#include "LinkedList.hpp"


using namespace std;

int main() {
    int s, h, w;
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

    // create a new linked list based on the height and weight provided
    LinkedList *ll = new LinkedList(h, w);
    
    cout << "How many points would you like to enter? >";
    cin >> s;
    if(s < 0) {
        cout << "ERROR: CANNOT ENTER A NEGATIVE NUMBER OF POINTS!";
        return 1;
    }
    int input[3];

    for(int i = 0; i < s; i++) { // prompt user for values
        cout << "Enter row position for point " << i + 1 << " >";
        cin >> input[0];
        if(input[0] >= h || input[0] < 0) {
            cout << "ERROR: OUT OF WIDTH BOUNDS!";
            return 1;
        }

        cout << "Enter column position for point " << i + 1 << " >";
        cin >> input[1];
        if(input[1] >= w || input[1] < 0) {
            cout << "ERROR: OUT OF WIDTH BOUNDS!";
            return 1;
        }

        cout << "Enter value for point " << i + 1 << " >";
        cin >> input[2];
        if(input[2] <= 0) {
            cout << "ERROR: CANNOT ENTER NONPOSITIVE OR ZERO VALUE!";
            return 1;
        }
        
        ll->appendNode(input[0], input[1], input[2]);
    }

    cout << "================================================" << endl;
    ll->printMatrix();
    cout << "================================================" << endl;
    ll->printNodes();

    delete ll;
    return 0;
}