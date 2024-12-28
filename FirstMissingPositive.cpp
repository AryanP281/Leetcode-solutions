
#include<bits/stdc++.h>

using namespace std;

int firstMissingPositive(vector<int>& nums);

int main()
{
    vector<int> nums = {3,4,-1,1};
    cout << firstMissingPositive(nums);

    getchar();
    return 0;
}

int firstMissingPositive(vector<int>& nums) 
{
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] <= 0 || nums[i] > nums.size())
            continue;

        while(nums[i] != i+1 && nums[i] > 0 && nums[i] <= nums.size())
        {
            int temp = nums[nums[i]-1];
            if(temp == nums[i])
                break;
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        if(i+1 != nums[i])
            return (i+1);   
    }

    return nums.size()+1;        
}