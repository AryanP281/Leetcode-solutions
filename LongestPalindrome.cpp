/*
#include<iostream>
#include<string>

using namespace std;

int longestPalindrome(string s)
{
    int chars[26 * 2] = { 0 };
    for (int a = 0; a < s.size(); ++a)
    {
        int index = islower(s[a]) ? s[a] - 'a' : 26 + s[a] - 'A';
        chars[index]++;
    }

    int palindromeSize = 0;
    bool isEven = true;
    for (int a = 0; a < 26 * 2; ++a)
    {
        if (chars[a] == 0) continue;

        if (chars[a] % 2 == 0) palindromeSize += chars[a];
        else
        {
            if (isEven)
            {
                palindromeSize += chars[a];
                isEven = false;
            }
            else
                palindromeSize += (chars[a] / 2) * 2;
        }
    }

    return palindromeSize;
}
*/