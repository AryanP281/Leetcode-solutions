
#include<bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums);

int main()
{
    vector<int> nums = {11,13,15,17};
    cout << findMin(nums);

    getchar();
    return 0;
}

int findMin(vector<int>& nums) 
{
    //Base case (rotated n times)
    if(*nums.begin() < *nums.rbegin())
        return nums[0];

    int l = 0;
    int r = nums.size() - 1;
    int n = nums.size();
    while(l <= r)
    {
        int m = floor((float)(l+r) / 2.0f);

        if(nums[((m-1) + n) % n] > nums[m] && nums[(m+1) % n] > nums[m])
            return nums[m];

        if(nums[m] < nums[0])
            r = m-1;
        else
            l = m+1;
    }   
}