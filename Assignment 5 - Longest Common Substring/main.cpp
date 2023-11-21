#include <iostream>
#include <stdlib.h>
#include "table.hpp"

using namespace std;

int main(){
    table * t = new table("seven", "eleven");
    t->printMatrix();
    t->longestCommonSubstring();
    cout << "after print" << endl;
    t->printMatrix();
};