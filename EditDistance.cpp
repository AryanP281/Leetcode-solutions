
#include<bits/stdc++.h>

using namespace std;

int minDistance(string word1, string word2);

int main()
{
    cout << minDistance("", "");

    getchar();
    return 0;
}

int minDistance(string word1, string word2) 
{
    int** dp = new int*[word1.size()+1];
    for(int r = 0; r < word1.size()+1; ++r)
    {
        dp[r] = new int[word2.size()+1]();
    }
    for(int c = 1; c < word2.size()+1; ++c)
    {
        dp[0][c] = dp[0][c-1] + 1;
    }
    for(int r = 1; r < word1.size()+1; ++r)
    {
        dp[r][0] = dp[r-1][0] + 1;
    }
    
    for(int r = 1; r < word1.size()+1; r++)
    {
        for(int c = 1; c < word2.size()+1; ++c)
        {
            if(word1[r-1] == word2[c-1])
                dp[r][c] = dp[r-1][c-1];
            else
                dp[r][c] = min(min(1+dp[r][c-1], 1+dp[r-1][c]),1+dp[r-1][c-1]);
        }
    }

    int editDistance = dp[word1.size()][word2.size()];

    for(int r = 0; r < word1.size()+1; ++r)
    {
        delete[] dp[r];
    }
    delete[] dp;

    return editDistance;
}