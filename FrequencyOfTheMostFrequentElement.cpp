
#include<bits/stdc++.h>

using namespace std;

int maxFrequency(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {1,2,4,5};

    cout << maxFrequency(nums, 5);

    getchar();
    return 0;
}

int maxFrequency(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end());

    int result = 0;
    int l = 0;
    int r = 0;

    uint64_t currSum = nums[0];
    while(r < nums.size())
    {
        if((uint64_t)nums[r]*(uint64_t)(r-l+1) - (uint64_t)currSum <= k)
        {
            result = max(result, r-l+1);
            r++;
            currSum += nums[min(r, (int)nums.size()-1)];
        }
        else
        {
            currSum -= nums[l];
            l++;
        }
    }

    return result;
}