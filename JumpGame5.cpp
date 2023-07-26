
#include<bits/stdc++.h>

using namespace std;

int maxJumps(vector<int>& arr, int d);
int getMaxJumps(int i, int& d, vector<int>& arr, int* dp);

int main()
{
    vector<int> arr = {66};

    cout << maxJumps(arr, 1);

    getchar();
    return 0;
}

int maxJumps(vector<int>& arr, int d) 
{
    int* dp = new int[arr.size()]();
    fill_n(dp, arr.size(), -1);

    int res = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        res = max(res, getMaxJumps(i,d,arr,dp));
    }

    delete[] dp;

    return res;
}

int getMaxJumps(int i, int& d, vector<int>& arr, int* dp)
{
    if(dp[i] != -1)
        return dp[i];

    dp[i] = 1;
    for(int j = i-1; j >= max(0, i-d); j--)
    {
        if(arr[j] >= arr[i])
            break;
        dp[i] = max(dp[i], 1 + getMaxJumps(j, d, arr, dp));
    }
    for(int j = i+1; j <= min((int)arr.size()-1, i+d); ++j)
    {
        if(arr[j] >= arr[i])
            break;
        dp[i] = max(dp[i], 1+getMaxJumps(j,d,arr,dp));
    }

    return dp[i];
}