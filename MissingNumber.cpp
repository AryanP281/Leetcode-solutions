
#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums);

int main()
{

    getchar();
    return 0;
}

int missingNumber(vector<int>& nums) 
{
    nums.push_back(nums.size()+1);
    for(int i = 0; i < nums.size()-1; ++i)
    {
        nums[i]++;
    }        

    for(int i = 0; i < nums.size()-1; ++i)
    {
        nums[abs(nums[i])-1] *= -1;
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > 0)
            return i;
    }

    return 0;
}

int missingNumber(vector<int>& nums) 
{
    int mask = 0;
    for(int i = 1; i <= nums.size(); ++i)
    {
        mask ^= i;
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        mask ^= nums[i];
    }

    return mask;
}