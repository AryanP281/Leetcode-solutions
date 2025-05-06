
#include<bits/stdc++.h>

using namespace std;

string shortestPalindrome(string s);

int main()
{
    string s = "abcd";
    cout << shortestPalindrome(s);

    getchar();

    return 0;
}

string shortestPalindrome(string s) 
{
    const uint64_t BASE = 29;
    const uint64_t MOD = 1e9+7;
    
    uint64_t prefixHash = 0;
    uint64_t suffixHash = 0;
    uint64_t currPower = 1;

    int longestMatch = -1;
    for(int i = 0; i < s.size(); ++i, currPower = (currPower*BASE) % MOD)
    {
        prefixHash = (prefixHash + currPower*(s[i] - 'a')) % MOD;
        suffixHash = (((suffixHash*BASE) % MOD) + (s[i] - 'a')) % MOD;

        if(prefixHash == suffixHash)
            longestMatch = i;
    }

    if(longestMatch < s.size())
    {
        string addition = s.substr(longestMatch+1, s.size()-max(0,longestMatch));
        reverse(addition.begin(), addition.end());
        string result = addition + s;
        return result;
    }
    
    return "";
}