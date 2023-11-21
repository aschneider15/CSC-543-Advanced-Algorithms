#include <iostream>
#include <stdlib.h>
#include "table.hpp"

using namespace std;

int main(){
    table * t = new table("hello world", "hi world");
    t->printMatrix();
    cout << "after print" << endl;
    cout << t->getValueAt(0, 4) << endl;
};