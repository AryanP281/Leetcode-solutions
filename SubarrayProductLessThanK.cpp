
#include<bits/stdc++.h>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {1,2,3};
    cout << numSubarrayProductLessThanK(nums, 0);

    getchar();
    return 0;
}

int numSubarrayProductLessThanK(vector<int>& nums, int k) 
{
    uint64_t currProd = 1;
    int subArrayCount = 0;

    int l = 0;
    for(int r = 0; r < nums.size(); ++r)
    {
        currProd *= nums[r];
        while(l <= r && currProd >= k)
        {
            currProd /= nums[l];
            l++;
        }
        subArrayCount += ((r-l)+1)*(l <= r);
    }

    return subArrayCount;
}