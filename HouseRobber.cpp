
#include<bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums);
int getMaxAmt(vector<int>& nums, int i, int* cache);

int main()
{
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums);

    getchar();
    return 0;
}

int rob(vector<int>& nums) 
{
    int* cache = new int[nums.size()];
    cache[0] = nums[0];
    fill_n(cache+1,nums.size()-1,-1);

    int maxAmt = getMaxAmt(nums, nums.size()-1, cache);

    delete[] cache;

    return maxAmt;
}

int getMaxAmt(vector<int>& nums, int i, int* cache)
{
    if(i < 0)
        return 0;

    if(cache[i] != -1)
        return cache[i];

    int includedAmt = nums[i]+getMaxAmt(nums, i-2,cache);
    int excludedAmt = getMaxAmt(nums,i-1,cache);
    cache[i] = ((includedAmt > excludedAmt) ? includedAmt : excludedAmt);

    return cache[i];
}