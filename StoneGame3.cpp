
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

string stoneGameIII(vector<int>& stoneValue); 
int getMaxScore(int i, vector<int>& stones, vector<int>& dp);

int main()
{
    vector<int> stones = {1,2,3,-9};
    cout << stoneGameIII(stones);

    getchar();
    return 0;
}

string stoneGameIII(vector<int>& stoneValue) 
{
    vector<int> dp(stoneValue.size(), INT_MIN);

    int aliceScore = -1*getMaxScore(0, stoneValue, dp); 
    if(aliceScore > 0)
        return "Alice";
    else if(aliceScore == 0)
        return "Tie";

    return "Bob";
}

int getMaxScore(int i, vector<int>& stones, vector<int>& dp)
{
    if(i >= stones.size())
        return 0;
    else if(dp[i] != INT_MIN)
        return dp[i] * -1;

    int currScore = 0;
    for(int j = i; j < i+3 && j < stones.size(); j++)
    {
        currScore += stones[j];
        dp[i] = max(dp[i], currScore + getMaxScore(j+1,stones,dp));
    }

    return dp[i]*-1;
}