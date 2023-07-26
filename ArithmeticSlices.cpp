
#include<bits/stdc++.h>

using namespace std;

int numberOfArithmeticSlices(vector<int>& nums);

int main()
{
    vector<int> nums = {11,12,15,18,19,20};
    cout << numberOfArithmeticSlices(nums);

    getchar();
    return 0;
}

int numberOfArithmeticSlices(vector<int>& nums) 
{
    if(nums.size() < 3)
        return 0;
    
    typedef pair<int,int> Vec;
    
    Vec prevSbarray(nums.size()-1, nums[nums.size()-1] - nums[nums.size()-2]);
    int slices = 0;
    for(int i = nums.size()-3; i >= 0; --i)
    {
        if(nums[i+1] - nums[i] == prevSbarray.second)
            slices +=  prevSbarray.first - i - 1;
        else
        {
            prevSbarray.first = i+1;
            prevSbarray.second = nums[i+1] - nums[i];
        }
    }

    return slices;
}