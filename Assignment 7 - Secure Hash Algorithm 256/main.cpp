#include <string.h>
#include "SHa.hpp"


int main() {
    char * input = "What is a man? A miserable little pile of secrets! But enough talk... have at you!";
    SHa * SHaObject = new SHa(input, strlen(input));
    return 0;
};