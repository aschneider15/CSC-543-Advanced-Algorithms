#include <iostream>
#include <stdlib.h>
#include "table.hpp"

using namespace std;

int main(){
    string s1, s2;
    cout << "Input first string > ";
    cin >> s1;
    cout << "Input second string > ";
    cin >> s2;
    
    table * t = new table(s1, s2);

    // we'll store the maximum length and the end index in this array
    string results;

    t->printMatrix();
    cout << "=======================" << endl;
    results = t->longestCommonSubstring();
    t->printMatrix();
    cout << "=======================" << endl;
    cout << "Longest common substring is: " << results << endl;
};