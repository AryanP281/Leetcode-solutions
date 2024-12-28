
#include<bits/stdc++.h>

using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal);

int main()
{

    vector<int> nums = {0,0,0,0,0};
    cout << numSubarraysWithSum(nums, 0);

    getchar();
    return 0;
}

int numSubarraysWithSum(vector<int>& nums, int goal) 
{
    vector<int> onePos = {-1};
    int currSum = 0;

    int subarrayCount = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        currSum += nums[i];

        if(nums[i])
            onePos.push_back(i);

        if(currSum >= goal)
        {
            int diff = currSum - goal;
            subarrayCount += onePos.size() > diff+1 ? onePos[diff+1] - onePos[diff] : i - onePos[diff]; 
        }

    }

    return subarrayCount;
}