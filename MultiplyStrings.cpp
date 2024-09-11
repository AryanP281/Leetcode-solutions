#include<bits/stdc++.h>

using namespace std;

string multiply(string num1, string num2);

int main()
{
    cout << multiply("123","456");

    getchar();
    return 0;
}

string multiply(string num1, string num2) 
{
    string& st1 = num1.size() > num2.size() ? num1 : num2;
    string& st2 = st1 == num1 ? num2 : num1;

    uint8_t** buffers = new uint8_t*[st2.size()];
    int nc = st1.size() + st2.size() + 1;
    for(int i = 0; i < st2.size(); ++i)
    {
        buffers[i] = new uint8_t[nc]();
    }

    for(int i = st2.size()-1; i >= 0; --i)
    {
        uint8_t d1 = st2[i] - '0';
        for(int j = st1.size()-1; j >= 0; j--)
        {
            uint8_t d2 = st1[j] - '0';
            uint8_t prod = d2*d1;

            int cell1 = buffers[st2.size()-1-i][nc-1-(st1.size()-1-j)-(st2.size()-1-i)] + prod;
            buffers[st2.size()-1-i][nc-1-(st1.size()-1-j)-(st2.size()-1-i)] = (cell1 % 10);
            buffers[st2.size()-1-i][nc-1-(st1.size()-1-j)-(st2.size()-1-i)-1] += (uint8_t)floor((double)cell1 / 10.0);
        }
    }

    string result = "";
    int carry = 0;
    for(int c = nc-1; c >= 0; --c)
    {
        int currSum = carry;
        for(int r = 0; r < st2.size(); ++r)
        {
            currSum += buffers[r][c];
        }
        result += '0' + (currSum % 10);
        carry = (int)floor((double)currSum/10.0);
    }

    while(*result.rbegin() == '0')
    {
        result.pop_back();
    }
    reverse(result.begin(), result.end());

    for(int i = 0; i < st2.size(); ++i)
    {
        delete[] buffers[i];
    }
    delete[] buffers;

    return result.size() == 0 ? "0" : result;
}