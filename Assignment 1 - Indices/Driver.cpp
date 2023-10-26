// This is a 'warm-up' assignment to refresh your understanding of Arrays in C++.
// Write C++ code to accomplish the following tasks:

// Given an array of integer nums and an integer target, return indices of the two numbers such that they add up to the target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order. 

#include <iostream>
#include <stdlib.h>
using namespace std;

// Prototypes

int main() {
    int arr[10] = {3,2,4};
    int target = 6;
    
    // size of array (in bytes) / size of integer (in bytes)
    int size = sizeof(arr)/sizeof(int);
    int pair[2]; 
    
    // iterate through each index
    for(int i = 0; i < size; i++) {
        // check with each subsequent index
        for(int j = i; j < size; j++) {
            // check if the two elements add up to desired sum
            if(arr[i] + arr[j] == target) {
                pair[0] = i;
                pair[1] = j;
            }
        }
    }

    cout << "Paired indices: " << pair[0] << ", " << pair[1] << endl;
};