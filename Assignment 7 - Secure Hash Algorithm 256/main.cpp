#include <string.h>
#include "SHa.hpp"


int main() {
    char * input = "AlphaBetaPrunings?!";
    SHa * SHaObject = new SHa(input, strlen(input));
    return 0;
};