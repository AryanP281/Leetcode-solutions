
#include<bits/stdc++.h>

using namespace std;

int stoneGameII(vector<int>& piles);
int getMaxScore(int i, int m, vector<int>& piles, vector<int>& sums, vector<vector<int>>& dp);

int main()
{
    vector<int> piles = {1,2,3,4,5,100};
    cout << stoneGameII(piles);

    getchar();
    return 0;
}

int stoneGameII(vector<int>& piles) 
{
    vector<int> suffixSums(piles.size()+1, 0);
    suffixSums[suffixSums.size()-1] = 0;
    for(int i = piles.size()-1; i >= 0; --i)
    {
        suffixSums[i] = suffixSums[i+1] + piles[i];
    }

    vector<vector<int>> dp(piles.size(), vector<int>(2*piles.size(), -1));

    return getMaxScore(0, 1, piles, suffixSums, dp);
}

int getMaxScore(int i, int m, vector<int>& piles, vector<int>& sums, vector<vector<int>>& dp)
{
    if(i >= piles.size())
        return 0;
    else if(dp[i][m] != -1)
        return dp[i][m];

    int oppScore = 0;
    int currScore = 0;
    for(int j = i; j < (i+2*m) && j < piles.size(); ++j)
    {
        currScore += piles[j];
        dp[i][m] = max(dp[i][m], currScore + (sums[j+1] - getMaxScore(j+1,max(m, j-i+1), piles, sums, dp)));
    }

    return dp[i][m];
}