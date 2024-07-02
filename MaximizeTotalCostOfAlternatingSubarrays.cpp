#include<bits/stdc++.h>

using namespace std;
long long maximumTotalCost(vector<int>& nums);

int main()
{
    vector<int> nums = {1,-1};
    cout << maximumTotalCost(nums);

    getchar();
    return 0;
}

long long maximumTotalCost(vector<int>& nums) 
{
    vector<vector<int64_t>> maxCosts;
    maxCosts.push_back({nums[0], nums[0]});

    for(int i = 1; i < nums.size(); ++i)
    {
        maxCosts.push_back(vector<int64_t>());
        maxCosts.rbegin()->push_back(max(maxCosts[i-1][0] + nums[i], maxCosts[i-1][1] + nums[i]));
        maxCosts.rbegin()->push_back(maxCosts[i-1][0] + -1*nums[i]);
    }        

    return max(maxCosts[nums.size()-1][0], maxCosts[nums.size()-1][1]);
}