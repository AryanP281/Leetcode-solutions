
#include<bits/stdc++.h>

using namespace std;

int minOperations(vector<int>& nums, int x);

int main()
{
    vector<int> nums = {5,6,7,8,9};

    cout << minOperations(nums, 4);

    getchar();
    return 0;
}

int minOperations(vector<int>& nums, int x) 
{

    int minOps = nums.size()+1;
    unordered_map<int,int> prefixSums[2];
    int rangeIndices[2] = {0, nums.size()-1};
    int currSum = 0;
    for(; rangeIndices[0] < nums.size() && currSum <= x; ++rangeIndices[0])
    {
        currSum += nums[rangeIndices[0]];
        prefixSums[0][currSum] = rangeIndices[0];
    }
    rangeIndices[0] -= 2;
    
    unordered_map<int,int>::iterator itr = prefixSums[0].find(x);
    if(itr != prefixSums[0].end())
        minOps = itr->second+1;

    currSum = 0;
    for(; rangeIndices[1] >= 0 && currSum <= x; --rangeIndices[1])
    {
        currSum += nums[rangeIndices[1]];
        prefixSums[1][currSum] = rangeIndices[1];
    }
    rangeIndices[1] += 2;

    itr = prefixSums[1].find(x);
    if(itr != prefixSums[1].end())
        minOps = min(minOps, (int)nums.size()-itr->second);

    currSum = 0;
    for(int i = 0; i <= rangeIndices[0]; ++i)
    {
        currSum += nums[i];
        itr = prefixSums[1].find(x - currSum);
        if(itr != prefixSums[1].end() && itr->second > i)
            minOps = min(minOps, (i+1)+((int)nums.size()-itr->second));
    }

    return minOps == nums.size()+1 ? -1 : minOps;
}