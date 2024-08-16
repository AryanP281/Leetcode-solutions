
#include<bits/stdc++.h>

using namespace std;

bool canPartition(vector<int>& nums);
bool partition(int i, int subsetSum, vector<int>& nums, int** dp);

int main()
{
    vector<int> nums = {1,2,3,4,5,5,6};
    cout << canPartition(nums);

    getchar();
    return 0;
}

bool canPartition(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());

    int numSum = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        numSum += nums[i];
    }

    if(numSum % 2)
        return false;

    int subsetSum = numSum / 2;
    int** dp = new int*[nums.size()];
    for(int r = 0; r < nums.size(); ++r)
    {
        dp[r] = new int[subsetSum+1];
        fill_n(&dp[r][0], subsetSum+1, -1);
    }

    bool result = partition(0, subsetSum, nums, dp);

    for(int r = 0; r < nums.size(); ++r)
    {
        delete[] dp[r];
    }
    delete[] dp;

    return result;
}

bool partition(int i, int subsetSum, vector<int>& nums, int** dp)
{
    if(subsetSum == 0)
        return true;
    else if(i >= nums.size() || subsetSum - nums[i] < 0)
        return false;
    else if(dp[i][subsetSum] != -1)
        return dp[i][subsetSum];

    dp[i][subsetSum] = 0;
    if(partition(i+1, subsetSum-nums[i], nums, dp) || partition(i+1,subsetSum,nums,dp))
        dp[i][subsetSum] = 1;

    return dp[i][subsetSum];
}