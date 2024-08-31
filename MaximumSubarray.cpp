
#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums);

int main()
{
    vector<int> nums = {-1,-2};
    cout << maxSubArray(nums);

    getchar();
    return 0;
}

int maxSubArray(vector<int>& nums) 
{
    int maxSum = INT_MIN;

    int currSum = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        if(currSum <= 0)
            currSum = 0;
    }

    return maxSum;
}