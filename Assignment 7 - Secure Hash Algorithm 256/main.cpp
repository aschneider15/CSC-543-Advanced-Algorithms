#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "SHa.hpp"

using namespace std;

int main() {
    // Import the file and process it to be used as a char *
    ifstream file("Mark.txt");
    string str((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    const char* gospel = str.c_str();

    SHa * gospelHash = new SHa(gospel, strlen(gospel));
};