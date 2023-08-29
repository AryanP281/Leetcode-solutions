
#include<bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target);

int main()
{

    vector<int> nums = {3,1};

    cout << search(nums, 1);

    getchar();
    return 0;
}

int search(vector<int>& nums, int target) 
{
    auto binarySearch = [&nums,&target]() -> int {
        int l = 0;
        int r = nums.size()-1;
        int m;
        int idx = -1;
        while(l <= r)
        {
            m = floor((float)(l+r)/2.0f);
            if(nums[m] == target)
            {
                idx = m;
                break;
            }
            else if(nums[m] > target)
                r = m-1;
            else
                l = m+1;
        }

        return idx;
    };
    
    //Checking if pivoted
    if(nums[0] < nums[nums.size()-1])
        return binarySearch();
    //Checking if target is pivot
    if(target == nums[0])
        return 0;

    int l = 0;
    int r = nums.size()-1;
    int m;
    int idx = -1;

    while(l <= r)
    {
        m = floor((float)(l+r)/2.0f);

        if(nums[m] == target)
            return m;

        if(target > nums[0])
        {
            if(nums[m] < nums[0] || (nums[m] > nums[0] && nums[m] > target))
                r = m-1;
            else
                l = m+1;
        }
        else
        {
            if(nums[m] >= nums[0] || (nums[m] < nums[0] && nums[m] < target))
                l = m+1;
            else
                r = m-1;
        }
    }

    return idx;
}