
#include<bits/stdc++.h>

using namespace std;

int numDecodings(string s);

int main()
{

    string s = "10";
    cout << numDecodings(s);

    getchar();
    return 0;
}

int numDecodings(string s) 
{
    int* dp = new int[s.size()+1]();
    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : -2;

    int encodedVal;
    for(int i = 2; i < s.size()+1; ++i)
    {
        dp[i] = dp[i-1]*(s[i-1] != '0');
        if(s[i-2] != '0')
        {
            encodedVal = (s[i-2] - '0')*10 + (s[i-1] - '0');
            if(encodedVal <= 26)
                dp[i] += dp[i-2];
        }
    }

    int res = max(0,dp[s.size()]);

    delete[] dp;

    return res;
}