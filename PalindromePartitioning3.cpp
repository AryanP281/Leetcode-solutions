
#include<bits/stdc++.h>

using namespace std;

int palindromePartition(string s, int k);
int getMinCost(int i, int k, vector<vector<int>>& costs, vector<vector<int>>& dp);

int main()
{
    cout << palindromePartition("abc",2);

    getchar();
    return 0;
}

int palindromePartition(string s, int k) 
{
    vector<vector<int>> palindromeCosts(s.size(), vector<int>(s.size(), 0));
    int offset = 1;
    for(int c = 1; c < s.size(); offset++, c = offset)
    {
        for(int r = 0; r < s.size() && c < s.size(); ++r, ++c)
        {
            palindromeCosts[r][c] = 1*(s[r] != s[c]) + palindromeCosts[r+1][c-1];
        }
    }

    vector<vector<int>> dp(s.size(), vector<int>(k, -1));
    return getMinCost(0, k, palindromeCosts, dp);
}

int getMinCost(int i, int k, vector<vector<int>>& costs, vector<vector<int>>& dp)
{
    if(i >= costs.size())
        return 0;
    else if(dp[i][k-1] != -1)
        return dp[i][k-1];
    

    if(k == 1)
        dp[i][k-1] = costs[i][costs.size()-1];
    else
    {
        dp[i][k-1] = INT_MAX;
        for(int j = i; j <= costs.size()-k && dp[i][k-1] != 0; ++j)
        {
            dp[i][k-1] = min(dp[i][k-1], costs[i][j] + getMinCost(j+1, k-1, costs, dp));
        }
    }
    
    return dp[i][k-1];
}