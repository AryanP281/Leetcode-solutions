
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int numSubarrayProductLessThanK(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {57,44,92,28,66,60,37,33,52,38,29,76,8,75,22};
    cout << numSubarrayProductLessThanK(nums,18);

    getchar();
    return 0;
}

int numSubarrayProductLessThanK(vector<int>& nums, int k) 
{
    if(k == 0)
        return 0;
    
    int l = 0;
    int r = -1;

    int currProd = 1;
    int sbCount = 0;
    while(++r < nums.size())
    {
        if(nums[r] >= k)
        {
            l = r;
            currProd = nums[r];
            continue;
        }

        currProd *= nums[r];
        while(l < r && currProd >= k)
        {   
            currProd /= nums[l]; 
            l++;
        }
        
        sbCount += (r-l)+1;
    }

    return sbCount;
}