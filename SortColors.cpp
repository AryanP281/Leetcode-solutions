
#include<bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums);
int partition(int l, int val, vector<int>& nums);

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);

    getchar();
    return 0;
}

void sortColors(vector<int>& nums) 
{
    int r = 0;
    for(int i = 0; i < 2; ++i)
    {
        r = partition(r, i, nums);
    }
}

int partition(int l, int val, vector<int>& nums)
{
    int s = l;
    for(int i = l; i < nums.size(); ++i)
    {
        if(nums[i] == val)
        {
            int temp = nums[s];
            nums[s] = nums[i];
            nums[i] = temp;
            s++;
        }
    }

    return s;
}

