#ifndef VOLE_MACHINE_TEST2_ALU_H
#define VOLE_MACHINE_TEST2_ALU_H

#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<unordered_map>
#include "Register.h"
using namespace std;

class ALU {
public:
    string hexToBin(string hexNumber);
    string binToHex(string& binNumber);
    string decToBin(string decNumber);
    string addWithTwosComplement(const string& num1,const string& num2);
    string normalAdd(const string& num1,const string& num2);
    void addHexNumbers(int regAddress1,int regAddress2,int regAddress3,Register& reg);
    void convertToTwosComplement(string& value);
    string floatToBinary(double floatNumber);
    double binaryToFloat(string &num);
    void addFloatPointNumber(int regAddress1,int regAddress2,int regAddress3,Register& reg);
};


#endif //VOLE_MACHINE_TEST2_ALU_H
