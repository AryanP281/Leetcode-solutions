
#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int numSubseq(vector<int>& nums, int target);
int binarySearch(vector<int>& nums, int ub);
int power(int64_t x, int64_t y);

int main()
{
    vector<int> nums = {14,4,6,6,20,8,5,6,8,12,6,10,14,9,17,16,9,7,14,11,14,15,13,11,10,18,13,17,17,14,17,7,9,5,10,13,8,5,18,20,7,5,5,15,19,14};
    cout << numSubseq(nums,22);

    getchar();
    return 0;
}

int numSubseq(vector<int>& nums, int target) 
{
    sort(nums.begin(), nums.end());

    int subSeqCount = 0;
    for(int i = 0; i < nums.size() && nums[i] < target; ++i)
    {
        int ub = target - nums[i];
        if(ub >= nums[i])
        {
            int range = binarySearch(nums, ub);
            if(range >= i)
                subSeqCount = (subSeqCount + power(2,range-i)) % MOD;
        }
    }     

    return subSeqCount;   
}

int binarySearch(vector<int>& nums, int ub)
{
    int pos = -1;
    int l = 0;
    int r = nums.size()-1;

    while(l <= r)
    {
        int mid = (l+r)/2;
        if(nums[mid] <= ub)
        {
            pos = mid;
            l = mid+1;
        }
        else
            r = mid-1;
    }

    return pos;
}

int power(int64_t x, int64_t y)
{
    if(x == 1 || y == 0)
        return 1;
    if(y == 1)
        return (x % MOD);
    if(x == 0)
        return 0;
    
    if((y % 2) == 0)
    {
        int64_t z = power(x, y / 2);
        int64_t res = (((z % MOD) * (z % MOD)) % MOD);
        return res;
    }
    
    int64_t z = power(x, y-1);
    return ((x*z) % MOD);
        
}