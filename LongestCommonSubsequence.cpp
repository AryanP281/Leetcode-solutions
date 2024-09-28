
#include<bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2);

int main()
{

    cout << longestCommonSubsequence("abcde", "ace");

    getchar();
    return 0;
}

int longestCommonSubsequence(string text1, string text2) 
{
    int** dp = new int*[text1.size()+1];
    for(int r = 0; r < text1.size()+1; ++r)
    {
        dp[r] = new int[text2.size()+1]();
    }

    for(int i = 0; i < text1.size(); i++)
    {
        for(int j = 0; j < text2.size(); ++j)
        {
            if(text1[i] == text2[j])
                dp[i+1][j+1] = 1 + dp[i][j];
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }

    int lcs = dp[text1.size()][text2.size()];

    for(int r = 0; r < text1.size()+1; ++r)
    {
        delete[] dp[r];
    }
    delete[] dp;

    return lcs;
}