
#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums);

int main()
{
    vector<int> nums = {1};
    cout << singleNumber(nums);

    getchar();
    return 0;
}

int singleNumber(vector<int>& nums) 
{
    int mask = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        mask ^= nums[i];
    }

    return mask;
}