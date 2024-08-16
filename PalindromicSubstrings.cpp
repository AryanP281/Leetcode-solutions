
#include<bits/stdc++.h>

using namespace std;

int countSubstrings(string s);

int main()
{
    cout << countSubstrings("aaa");

    getchar();
    return 0;
}

int countSubstrings(string s) 
{
    bool** dp = new bool*[s.size()];
    for(int i = 0; i < s.size(); ++i)
    {
        dp[i] = new bool[s.size()]();
        dp[i][i] = true;
    }

    for(int w = 2; w <= s.size(); ++w)
    {
        for(int l = 0; l+w-1 < s.size(); ++l)
        {
            int r = l+w-1;
            if(s[l] == s[r] && (w==2 || dp[l+1][r-1]))
                dp[l][r] = true;
        }
    }

    int substrCount = 0;
    for(int r = 0; r < s.size(); ++r)
    {
        for(int c = 0; c < s.size(); ++c)
        {
            substrCount += 1*(dp[r][c]);
        }
    }

    for(int i = 0; i < s.size(); ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;

    return substrCount;      
}