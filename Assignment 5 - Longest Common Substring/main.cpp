#include <iostream>
#include <stdlib.h>
#include "table.hpp"

using namespace std;

int main(){
    table * t = new table("seven", "eight");
    t->printMatrix();
    t->setValueAt(0, 4, 6);
    cout << "after print" << endl;
    t->printMatrix();
};