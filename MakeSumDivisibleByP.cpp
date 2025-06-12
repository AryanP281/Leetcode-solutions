
#include<bits/stdc++.h>

using namespace std;

int minSubarray(vector<int>& nums, int p);

int main()
{
    vector<int> nums = {1,2,3};
    cout << minSubarray(nums, 3);

    getchar();
    return 0;
}

int minSubarray(vector<int>& nums, int p) 
{
    int64_t rightSum = 0;
    for(int& num : nums)
    {
        rightSum += (int64_t)num;
    }
    
    if((rightSum % p) == 0)
        return 0;
    
    unordered_map<int,int> seenMods;
    seenMods[0] = -1;
    int64_t leftSum = 0;
    int minSize = nums.size();
    for(int i = 0; i < nums.size(); ++i)
    {
        leftSum += (int64_t)nums[i];
        rightSum -= (int64_t)nums[i];

        int currMod = (leftSum % (int64_t)p);
        int leftRequiredMod = ((int64_t)p - (rightSum % (int64_t)p)) % (int64_t)p;
        
        unordered_map<int,int>::iterator itr = seenMods.find(leftRequiredMod);
        if(itr != seenMods.end())
            minSize = min(minSize, i - itr->second);

        seenMods[currMod] = i;
    }

    return minSize == nums.size() ? -1 : minSize;
}