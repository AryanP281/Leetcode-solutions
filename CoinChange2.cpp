
#include<bits/stdc++.h>

using namespace std;

int change(int amount, vector<int>& coins);

int main()
{
    vector<int> coins = {10};
    cout << change(10,coins);

    getchar();
    return 0;
}

int change(int amount, vector<int>& coins) 
{
    int** dp = new int*[amount+1];
    for(int r = 0; r < amount+1; ++r)
    {
        dp[r] = new int[coins.size()+1]();
    }

    for(int r = 0; r < amount+1; ++r)
    {
        dp[r][0] = 0;
    }
    for(int c = 0; c < coins.size()+1; ++c)
    {
        dp[0][c] = 1;
    }

    for(int r = 1; r <= amount; ++r)
    {
        for(int c = 1; c < coins.size()+1; ++c)
        {
            if(coins[c-1] > r)
                dp[r][c] = dp[r][c-1];
            else
            {
                dp[r][c] = dp[r][c-1] + dp[r-coins[c-1]][c];
            }
        }
    }

    int combsCount = dp[amount][coins.size()];

    for(int r = 0; r < amount+1; ++r)
    {
        delete[] dp[r];
    }
    delete[] dp;

    return combsCount;   
}