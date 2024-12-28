
#include<bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums);

int main()
{
    vector<int> nums = {0};
    moveZeroes(nums);

    getchar();
    return 0;
}

void moveZeroes(vector<int>& nums) 
{
    int offset = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == 0)
            offset++;
        else if(offset > 0)
            nums[i - offset] = nums[i];
    }

    for(int i = nums.size()-1; i >= nums.size()-offset && i >= 0; --i)
    {
        nums[i] = 0;
    }


}