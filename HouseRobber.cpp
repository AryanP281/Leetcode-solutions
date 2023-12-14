
#include<bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums);

int main()
{
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums);

    getchar();
    return 0;
}

int rob(vector<int>& nums) 
{
    int* dp = new int[nums.size()+2]();

    for(int i = nums.size()-1; i >= 0; --i)
    {
        dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
    }

    int res = dp[0];

    delete[] dp;

    return res;
}