
#include<bits/stdc++.h>

using namespace std;

int maxSubarrayLength(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {1,2,1,2,1,2,1,2};

    cout << maxSubarrayLength(nums, 1);

    getchar();
    return 0;
}

int maxSubarrayLength(vector<int>& nums, int k) 
{
    unordered_map<int,int> freqs;
    int maxLen = 0;
    int l = 0;
    for(int r = 0; r < nums.size(); ++r)
    {
        freqs[nums[r]]++;

        while(freqs[nums[r]] > k)
        {
            freqs[nums[l]]--;
            if(freqs[nums[l]] == 0)
                freqs.erase(nums[l]);
            l++;
        }

        maxLen = max(maxLen, r-l+1);
    }

    return maxLen;
}