
#include<bits/stdc++.h>

using namespace std;

int maxCoins(vector<int>& nums);
int getMaxCoins(int l, int r, vector<int>& nums, int** dp);

int main()
{
    vector<int> nums = {1,5};
    cout << maxCoins(nums);

    getchar();

    return 0;
}

int maxCoins(vector<int>& nums) 
{
    int** dp = new int*[nums.size()];
    for(int i = 0; i < nums.size(); ++i)
    {
        dp[i] = new int[nums.size()];
        fill_n(dp[i], nums.size(), -1);
    }

    int result = getMaxCoins(0, nums.size()-1, nums, dp);

    for(int i = 0; i < nums.size(); ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;   

    return result;     
}

int getMaxCoins(int l, int r, vector<int>& nums, int** dp)
{
    if(r < l)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];

    int leftEnd = (l == 0) ? 1 : nums[l-1];
    int rightEnd = (r == nums.size()-1) ? 1 : nums[r+1];
    for(int i = l; i <= r; ++i)
    {
        //Getting the best possbile value if nums[i] is the last balloon popped (for all balloons between l to r)
        dp[l][r] = max(dp[l][r],
        getMaxCoins(l,i-1,nums,dp) + (leftEnd*nums[i]*rightEnd) + getMaxCoins(i+1,r,nums,dp)
        );
    }

    return dp[l][r];
}