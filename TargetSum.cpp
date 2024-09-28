
#include<bits/stdc++.h>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target);
int findWays(int i, int target, vector<int>& nums, unordered_map<int,int>* dp);

int main()
{
    vector<int> nums = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
    cout << findTargetSumWays(nums, 1000);

    getchar();
    return 0;
}

int findTargetSumWays(vector<int>& nums, int target) 
{
    unordered_map<int,int>* dp = new unordered_map<int,int>[nums.size()];

    int ways = findWays(0, target, nums, dp);

    delete[] dp;

    return ways;
}

int findWays(int i, int target, vector<int>& nums, unordered_map<int,int>* dp)
{
    if(i == nums.size())
        return 1*(target == 0);
    
    unordered_map<int,int>::iterator itr = dp[i].find(target);
    if(itr != dp[i].end())
        return itr->second;

    int ways = findWays(i+1, target+nums[i], nums, dp) + findWays(i+1, target-nums[i], nums, dp); 
    dp[i][target] = ways;

    return ways;
}

// int findTargetSumWays(vector<int>& nums, int target) 
// {
//     int sumCount = 0;
//     generateCombos(0, 0, &sumCount, target, nums);

//     return sumCount;
// }

// void generateCombos(int i, int currSum, int* sumCount, int target, vector<int>& nums)
// {
//     if(i == nums.size())
//     {
//         if(currSum == target)
//             (*sumCount)++;
//         return;
//     }

//     generateCombos(i+1, currSum + nums[i], sumCount, target, nums);
//     generateCombos(i+1,currSum-nums[i],sumCount,target,nums);
// }