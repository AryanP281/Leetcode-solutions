
#include<bits/stdc++.h>

using namespace std;

int getProfit(int i, int s, vector<int>& prices, int** dp);

int main()
{


    getchar();
    return 0;
}

int maxProfit(vector<int>& prices) 
{
    int** dp = new int*[prices.size()];
    for(int i = 0; i < prices.size(); ++i)
    {
        dp[i] = new int[2];
        fill_n(&dp[i][0], 2, -1);
    }

    int res = getProfit(0, 1, prices, dp);

    for(int i = 0; i < prices.size(); ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;

    return res;
}

int getProfit(int i, int s, vector<int>& prices, int** dp)
{
    if(i >= prices.size())
        return 0;
    else if(dp[i][s] != -1)
        return dp[i][s];

    if(s == 0)
        dp[i][s] = max(prices[i] + getProfit(i+2, 1, prices, dp), getProfit(i+1,0,prices,dp));
    else
        dp[i][s] = max(getProfit(i+1,0,prices,dp)-prices[i], getProfit(i+1,1,prices,dp));

    return dp[i][s];
}