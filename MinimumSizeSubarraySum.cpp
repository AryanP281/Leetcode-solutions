
#include<bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums);

int main()
{
    vector<int> nums = {1,2,3,4,5};
    cout << minSubArrayLen(11, nums);

    getchar();
    return 0;
}

int minSubArrayLen(int target, vector<int>& nums) 
{
    int minLen = nums.size()+1;

    int currSum = 0;
    int l = 0;
    for(int r = 0; r < nums.size(); ++r)
    {
        currSum += nums[r];
        if(currSum >= target)
        {
            do
            {
                minLen = min(minLen, r-l+1);
                currSum -= nums[l++];
            } while(l <= r && currSum >= target);
        }
    }
    
    return minLen == nums.size()+1 ? 0 : minLen;
}