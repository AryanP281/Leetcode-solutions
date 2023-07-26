
#include<bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums);
bool checkWindow(int len, vector<int>& nums, int target);

int main()
{
    vector<int> nums = {2,3,1,2,4,3};

    cout << minSubArrayLen(7, nums);

    getchar();
    return 0;
}

int minSubArrayLen(int target, vector<int>& nums) 
{
    int l = 0;
    int r = nums.size();
    int mid = 0;

    int minLen = nums.size()+1;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(checkWindow(mid, nums, target))
        {
            minLen = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }

    return minLen > nums.size() ? 0 : minLen;
}

bool checkWindow(int len, vector<int>& nums, int target)
{
    if(len == 0)
        return false;
    
    int windowSum = 0;
    int r = 0;
    for(; r < len; ++r)
    {
        windowSum += nums[r];
    }

    int l = 0;
    while(r < nums.size()-1 && windowSum < target)
    {
        r++;

        windowSum -= nums[l];
        windowSum += nums[r];

        l++;
    }

    return windowSum >= target;
}

/*
int minSubArrayLen(int target, vector<int>& nums) 
{
    int minLen = INT_MAX;
    int l = 0;
    int r = 0;
    int currSum = 0;
    for(; r < nums.size() && currSum < target; ++r)
    {
        currSum += nums[r];
    }
    if(currSum < target)
        return 0;

    r--;
    currSum -= nums[r];

    for(; r < nums.size(); ++r)
    {
        currSum += nums[r];
        while(l <= r && currSum >= target)
        {
            currSum -= nums[l];
            l++;
        }
        l--;
        currSum += nums[l];
        
        minLen = min(minLen, r-l+1);
    }

    return minLen;
}

{
class BIT
{
private:
    int* bits;
    int n;

public:
    BIT(int n)
    {
        this->n = n;
        bits = new int[n]();
    }

    ~BIT()
    {
        delete[] bits;
    }

    void set(int i, int val)
    {
        for(; i < n; i = i | (i+1))
        {
            bits[i] = val;
        }
    }

    int get(int i)
    {
        int res = INT_MIN;
        for(; i >= 0; i = (i & (i+1))-1)
        {
            res = max(res, bits[i]);
        }

        return res;
    }
};

int minSubArrayLen(int target, vector<int>& nums) 
{
    int maxSum = accumulate(nums.begin(), nums.end(), 0);
    BIT bit(maxSum);
    bit.set(0,-1);

    int cumSum = 0;
    int minLen = nums.size()+1;
    set<int> sums;
    sums.insert(0);
    for(int i = 0; i < nums.size(); ++i)
    {
        cumSum += nums[i];
        if(cumSum >= target)
        {
            set<int>::iterator lb = sums.lower_bound(cumSum - target);
            if(lb != sums.end() && (*lb == cumSum-target || lb != sums.begin()))
                minLen = min(minLen, i-bit.get(cumSum - target));
        }

        bit.set(cumSum, i);
        sums.insert(cumSum);
    }

    return minLen > nums.size() ? 0 : minLen;
}

}
*/