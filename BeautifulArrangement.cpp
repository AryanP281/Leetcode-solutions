
#include<bits/stdc++.h>

using namespace std;

int countArrangement(int n);
int getBeautiful(int i, int n, int mask, vector<vector<int>>& dp);

int main()
{
    cout << countArrangement(1);

    getchar();
    return 0;
}

int countArrangement(int n) 
{
    vector<vector<int>> dp(n, vector<int>(INT16_MAX, -1));

    return getBeautiful(0, n, 0, dp);
}

int getBeautiful(int i, int n, int mask, vector<vector<int>>& dp)
{
    if(i >= n)
        return 1;
    else if(dp[i][mask] != -1)
        return dp[i][mask];

    dp[i][mask] = 0;
    for(int j = 0; j < 15 && (j+1) <= n ; ++j)
    {
        if((mask & (1 << j)))
            continue;
        
        if((j+1) % (i+1) == 0 || (i+1) % (j+1) == 0)
            dp[i][mask] += getBeautiful(i+1, n, mask | (1 << j), dp);
    }

    return dp[i][mask];
}