
#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string s);

int main()
{

    string str = "aaaa";
    cout << longestPalindrome(str);

    getchar();

    return 0;
}

string longestPalindrome(string s) 
{
    bool** isPalindrome = new bool*[s.size()];
    for(int r = 0; r < s.size(); ++r)
    {
        isPalindrome[r] = new bool[s.size()]();
    }

    int maxPalindromeSize = 1;
    int maxPalindromeStart = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        isPalindrome[i][i] = true;
    }

    for(int l = 1; l < s.size(); ++l)
    {
        for(int r = 0; r + l < s.size(); ++r)
        {
            if(s[r] == s[r+l])
            {
                if((l > 1 && isPalindrome[r+1][r+l-1]) || l == 1)
                {
                    isPalindrome[r][r+l] = true;
                    maxPalindromeSize = l+1;
                    maxPalindromeStart = r;
                }
            }
        }
    }

    for(int r = 0; r < s.size(); ++r)
    {
        delete[] isPalindrome[r];
    }
    delete[] isPalindrome;

    return s.substr(maxPalindromeStart, maxPalindromeSize);
}