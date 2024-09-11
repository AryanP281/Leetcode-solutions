
#include<bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p);


int main()
{
    cout << isMatch("aa","a*");

    getchar();
    return 0;
}

bool isMatch(string s, string p) 
{
    bool** dp = new bool*[s.size()+1];
    for(int i = 0; i <= s.size(); ++i)
    {
        dp[i] = new bool[p.size()+1]();
    }
    dp[0][0] = true;
    for(int c = 1; c <= p.size(); ++c)
    {
        if(p[c-1] == '*')
            dp[0][c] = dp[0][c-2];
    }


    for(int r = 1; r <= s.size(); ++r)
    {
        for(int c = 1; c <= p.size(); ++c)
        {
            if(s[r-1] == p[c-1] || p[c-1] == '.')
                dp[r][c] = dp[r-1][c-1];
            else if(p[c-1] == '*')
                dp[r][c] = ((s[r-1] == p[c-2] || p[c-2] == '.') && dp[r-1][c]) || dp[r][c-2];
        }
    }

    bool match = dp[s.size()][p.size()];

    for(int i = 0; i < s.size(); ++i)
    {
        delete[] dp[i];
    }    
    delete[] dp;

    return match;
}