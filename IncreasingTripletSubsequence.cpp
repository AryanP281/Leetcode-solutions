
#include<bits/stdc++.h>

using namespace std;

bool increasingTriplet(vector<int>& nums);

int main()
{
    vector<int> nums = {0,4,2,1,0,-1,-3};
    cout << (increasingTriplet(nums) ? "True" : "False");

    getchar();
    return 0;
}

bool increasingTriplet(vector<int>& nums) 
{
    int smallest = INT_MIN;
    int mid = INT_MAX;

    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] <= smallest)
            smallest = nums[i];
        else if(nums[i] <= mid)
            mid = nums[i];
        else
            return true;
    }

    return false;
}