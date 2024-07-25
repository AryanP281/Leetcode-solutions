
#include<bits/stdc++.h>

using namespace std;

bool isInterleave(string s1, string s2, string s3);
int8_t checkSol(int j, int i, string& s1, string& s2, string& s3, int8_t** dp);

int main()
{

    cout << isInterleave("aabcc","dbbca","aadbbcbcac");

    getchar();
    return 0;
}

bool isInterleave(string s1, string s2, string s3) 
{
    if(s1.size() + s2.size() != s3.size())
        return false;

    int8_t** dp = new int8_t*[s3.size()];
    for(int i = 0; i < s3.size(); ++i)
    {
        dp[i] = new int8_t[s1.size()+1];
        for(int j = 0; j < s1.size()+1; ++j)
        {
            dp[i][j] = -1;
        }
    }

    bool isInterleaved = (checkSol(0,0,s1,s2,s3,dp) > 0);

    for(int i = 0; i < s3.size(); ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;

    return isInterleaved;
}

int8_t checkSol(int j, int i, string& s1, string& s2, string& s3, int8_t** dp)
{
    if(j == s3.size())
        return 1;
    
    if(dp[j][i] != -1)
        return dp[j][i];

    int p2 = j-i;
    if(i == s1.size())
    {
        if(s2[p2] != s3[j])
            dp[j][i] = 0;
        else
            dp[j][i] = checkSol(j+1,i,s1,s2,s3,dp);
    }
    else if(p2 == s2.size())
    {
        if(s1[i] != s3[j])
            dp[j][i] = 0;
        else
            dp[j][i] = checkSol(j+1,i+1,s1,s2,s3,dp);
    }
    else
    {
        if(s1[i] != s3[j] && s2[p2] != s3[j])
            dp[j][i] = 0;
        else
        {
            if(s1[i] != s3[j])
                dp[j][i] = checkSol(j+1,i,s1,s2,s3,dp);
            else if(s2[p2] != s3[j])
                dp[j][i] = checkSol(j+1,i+1,s1,s2,s3,dp);
            else
                dp[j][i] = min(1, checkSol(j+1,i,s1,s2,s3,dp) + checkSol(j+1,i+1,s1,s2,s3,dp));
        }
    }

    return dp[j][i];
}