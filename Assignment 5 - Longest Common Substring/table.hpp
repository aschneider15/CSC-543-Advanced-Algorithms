#include <stdlib.h>
#include <iostream>

#ifndef TABLE_HPP
#define TABLE_HPP

class table
{

private:
    std::string s1, s2;
    int ** mat;
    int rowsize;
    int colsize;

protected:
public:
    table(std::string s1, std::string s2);
    ~table();
    
    int getValueAt(int row, int col);
    void setValueAt(int row, int col, int val);
    
    void printMatrix();
    std::string longestCommonSubstring(); 
};

#endif 