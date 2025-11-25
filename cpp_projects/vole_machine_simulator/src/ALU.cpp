#include "ALU.h"

string ALU::hexToBin(string hexNumber)
{
    unordered_map<char , string>  bitsHex =
            {
                    {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
                    {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
                    {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
                    {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
            };
    string binary;
    for (char c : hexNumber)
    {
        if (islower(c))
        {
            c = toupper(c);
        }
        binary += bitsHex[c];
    }
    if(binary.length() != 8)
    {
        binary.insert(0,8 - binary.length(),'0');
    }
    return binary;
}
//=============================================================

string ALU::binToHex(string& binary)
{
    unordered_map<string, char> bitsBinary =
            {
                    {"0000", '0'},
                    {"0001", '1'},
                    {"0010", '2'},
                    {"0011", '3'},
                    {"0100", '4'},
                    {"0101", '5'},
                    {"0110", '6'},
                    {"0111", '7'},
                    {"1000", '8'},
                    {"1001", '9'},
                    {"1010", 'A'},
                    {"1011", 'B'},
                    {"1100", 'C'},
                    {"1101", 'D'},
                    {"1110", 'E'},
                    {"1111", 'F'}
            };
    if(binary.length() != 8)
    {
        binary.insert(0,8 - binary.length(),'0');
    }
    string hexNumber;
    for (int i = 0; i < binary.size(); i += 4)
    {
        string digits = binary.substr(i, 4);
        hexNumber += bitsBinary[digits];
    }
    return hexNumber;
}
//=============================================================

string ALU::decToBin(string decNumber)
{
    if(stoi(decNumber) == 0)
    {
        return "0";
    }
    int newNum = stoi(decNumber);
    string binNumber;
    while(newNum > 0)
    {
        int reminder = newNum % 2;
        binNumber = to_string(reminder) + binNumber;
        newNum /= 2;
    }
    return binNumber;
}
// =============================================================

string ALU::normalAdd(const string &num1, const string &num2)
{
    int carry = 0;
    string result;
    for(int i = num1.length() - 1;i>=0;i--)
    {
        int bit_num1 = num1[i] - '0';
        int bit_num2 = num2[i] - '0';
        int sum = bit_num1 + bit_num2 + carry;
        int result_bit = sum % 2;
        carry = sum / 2;
        result = to_string(result_bit) + result;
    }
    return result;
}
//=============================================================

string ALU::addWithTwosComplement(const string& num1,const string& num2)
{
    int carry = 0;
    string result;
    for(int i = num1.length() - 1;i>=0;i--)
    {
        int bit_num1 = num1[i] - '0';
        int bit_num2 = num2[i] - '0';
        int sum = bit_num1 + bit_num2 + carry;
        int result_bit = sum % 2;
        carry = sum / 2;
        result = to_string(result_bit) + result;
    }
    if(carry != 1)
    {
        convertToTwosComplement(result);
    }
    string hexValue = binToHex(result);
    return hexValue;
}

// =============================================================

void ALU::addHexNumbers(int regAddress1, int regAddress2, int regAddress3, Register &reg)
{
    string valueBin1 = hexToBin( reg.getRegister(regAddress2) );
    string valueBin2 = hexToBin( reg.getRegister(regAddress3) );

    if(valueBin1.length() != 8)
    {
        valueBin1.insert(0,8 - valueBin1.length(),'0');
    }
    if(valueBin2.length() != 8)
    {
        valueBin2.insert(0,8 - valueBin2.length(),'0');
    }
    bool b1 = false,b2 = false;
    if(valueBin1[0] == '1')
    {
        b1 = true;
    }
    if(valueBin2[0] == '1')
    {
        b2 = true;
    }
    if(b1 || b2)
    {
        string hexValue = addWithTwosComplement(valueBin1,valueBin2);
        reg.setRegister(regAddress1,hexValue);
    }
    else
    {
        string binResult = normalAdd(valueBin1,valueBin2);
        if(binResult.length() != 8)
        {
            binResult.insert(0,8 - binResult.length(),'0');
        }
        string hexResult = binToHex(binResult);
        reg.setRegister(regAddress1,hexResult);
    }
}
// =============================================================

void ALU::convertToTwosComplement(string& value)
{
    reverse(value.begin(),value.end());
    size_t found_1 = value.find('1');
    if(found_1 != string::npos)
    {
        for(size_t i = found_1 + 1;i < value.length();i++)
        {
            if(value[i] == '1')
            {
                value[i] = '0';
            }
            else if(value[i] == '0')
            {
                value[i] = '1';
            }
        }
    }
    reverse(value.begin(),value.end());
}
// =============================================================

string ALU::floatToBinary(double floatNumber)
{
    string sign = "0";
    if(floatNumber < 0.0)
    {
        sign = "1";
        floatNumber = abs(floatNumber);
    }
    int ex = 0;
    while(floatNumber >= 2.0)
    {
        floatNumber /= 2.0;
        ex++;
    }
    while(floatNumber < 1.0)
    {
        floatNumber *= 2.0;
        ex--;
    }
    ex += 4;
    string exValue = decToBin(to_string(ex));
    if(exValue.length() <3)
    {
        exValue.insert(0,3 - exValue.length(),'0');
    }
    floatNumber -= 1.0;
    vector<int>vec(4,0);
    for(int i = 0;i< 4;i++)
    {
        floatNumber *= 2;
        if(floatNumber >=1.0)
        {
            vec[i] = 1;
            floatNumber -= 1.0;
        }
    }
    string mantesa;
    for(auto& it:vec)
    {
        mantesa += to_string(it);
    }
    return sign + exValue + mantesa;
}
//=============================================================

double ALU::binaryToFloat(string &num)
{
    vector<string>vec;
    vec.push_back(num.substr(0,1));
    vec.push_back(num.substr(1,3));
    vec.push_back(num.substr(4));

    string newValue = vec[2];

    int ex = stoi(vec[1], nullptr,2);
    ex -= 4;
    double mantesa = 1.0;

    for(int i = 0;i<4;i++)
    {
        if(newValue[i] == '1')
        {
            mantesa += (1/pow(2,i+1));
        }
    }
    mantesa *= pow(2,ex);
    if(vec[0] == "1")
    {
        mantesa = -mantesa;
    }
    return mantesa;
}
// =============================================================

void ALU::addFloatPointNumber(int regAddress1, int regAddress2, int regAddress3, Register &reg)
{
    string binValue1 = hexToBin(reg.getRegister(regAddress2));
    string binValue2 = hexToBin(reg.getRegister(regAddress3));

    double floatNumber1 = binaryToFloat(binValue1);
    double floatNumber2 = binaryToFloat(binValue2);

    double addFloat = floatNumber1 + floatNumber2;

    string binFloat = floatToBinary(addFloat);

    string hexFloat = binToHex(binFloat);

    reg.setRegister(regAddress1,hexFloat);
}