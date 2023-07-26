
#include<bits/stdc++.h>

using namespace std;

int atMostNGivenDigitSet(vector<string>& digits, int n);
vector<int> getDigits(int x);

int main()
{
    vector<string> digits = {"7"};
    cout << atMostNGivenDigitSet(digits, 8);

    getchar();
    return 0;
}

int atMostNGivenDigitSet(vector<string>& digits, int n) 
{
    vector<int> nDigits = getDigits(n);

    vector<int> intDigits(digits.size(), 0);
    for(int a = 0; a < digits.size(); ++a)
    {
        intDigits[a] = digits[a][0] - '0';
    }

    vector<int64_t*> lookupTable;
    lookupTable.push_back(new int64_t[2]);
    lookupTable[0][0] = digits.size();
    lookupTable[0][1] = 0;
    for(int i = 0; i < intDigits.size() && intDigits[i] <= nDigits[0]; ++i)
    {
        lookupTable[0][1]++;
    }

    //Bottom-Up
    int64_t *t1, *t2;
    for(int i = 1; i < nDigits.size(); ++i)
    {
        lookupTable.push_back(new int64_t[2]);
        t1 = *lookupTable.rbegin();
        t2 = *lookupTable.rbegin()+1;
        
        for(int8_t j = 0; j < 2; ++j)
        {
            lookupTable[i][j] = 0;
            for(int k = 0; k < intDigits.size() && (j == 0 || intDigits[k] <= nDigits[i]); ++k)
            {
                lookupTable[i][j] += lookupTable[i-1][j && (intDigits[k] == nDigits[i])];
            }
        }
    }

    int result = 0;
    for(int i = 0; i < nDigits.size(); ++i)
    {
        result += lookupTable[i][i == (nDigits.size()-1)];
    }

    for(int a = 0; a < lookupTable.size(); ++a)
    {
        delete[] lookupTable[a];
    }

    return result;
}

vector<int> getDigits(int x)
{
    vector<int> digits;
    while(x != 0)
    {
        digits.push_back(x % 10);
        x /= 10;
    }

    return digits;
}

