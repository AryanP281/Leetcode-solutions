/*
#include<iostream>
#include<string>

using namespace std;

string addBinary(string a, string b);

void main()
{
    cout << addBinary("11", "1");
}

int getStringLength(string& str)
{
    return str.size() / sizeof(char);
}

short getBit(char ch)
{
    return 1 * (ch == '1') + 0 * (ch == '0');
}

char getChar(short bit)
{
    return bit == 1 ? '1' : '0';
}

string addBinary(string a, string b)
{
    string binaryAddition;
    string* largerString = getStringLength(a) > getStringLength(b) ? &a : &b;
    string* smallerString = largerString == &a ? &b : &a;
    int smallerStrLen = getStringLength(*smallerString);
    int largerStrLen = getStringLength(*largerString);
    short carryOver = 0;
    for (int a = 1; a <= smallerStrLen; ++a)
    {
        short bit1 = getBit(smallerString->at(smallerStrLen - a));
        short bit2 = getBit(largerString->at(largerStrLen - a));
        short sum = bit1 + bit2 + carryOver;
        carryOver = floor(sum / 2);
        binaryAddition += getChar(sum % 2);
    }

    for (int b = smallerStrLen + 1; b <= largerStrLen; ++b)
    {
        short bit = getBit(largerString->at(largerStrLen - b));
        short sum = bit + carryOver;
        carryOver = floor(sum / 2);
        binaryAddition += getChar(sum % 2);
    }

    if (carryOver == 1) binaryAddition += '1';

    reverse(binaryAddition.begin(), binaryAddition.end());

    return binaryAddition;
}*/