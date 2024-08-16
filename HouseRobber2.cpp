
#include<bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums);
int linearRob(vector<int>& nums);

int main()
{
    vector<int> nums = {0,0};
    cout << rob(nums);

    getchar();
    return 0;
}

int rob(vector<int>& nums) 
{
   if(nums.size() == 1)
    return nums[0];
   
   vector<int> modfNums(nums.begin(), prev(nums.end()));
   int sol1 = linearRob(modfNums);
   modfNums = vector<int>(next(nums.begin()), nums.end());
   return max(sol1, linearRob(modfNums));   
}

int linearRob(vector<int>& nums)
{
    int prevResults[2] = {-1,nums[0]};
    int currResult = nums[0];
    for(int i = 1; i < nums.size(); prevResults[0] = prevResults[1], prevResults[1] = currResult, i++)
    {
        currResult = max(nums[i],prevResults[1]);
        if(i - 2 >= 0)
            currResult = max(currResult, nums[i] + prevResults[0]);
    }

    return currResult;  
}