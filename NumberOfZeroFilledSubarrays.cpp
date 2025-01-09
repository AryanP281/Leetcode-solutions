
#include<bits/stdc++.h>

using namespace std;

long long zeroFilledSubarray(vector<int>& nums);

int main()
{
    vector<int> nums = {0,0,0,2,0,0};
    cout << zeroFilledSubarray(nums);

    getchar();
    return 0;
}

long long zeroFilledSubarray(vector<int>& nums) 
{
    int currSubarrayStart = -1;
    long long subarrayCount = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == 0)
        {
            if(currSubarrayStart == -1)
                currSubarrayStart = i;
            subarrayCount += (long long)(i-currSubarrayStart) + 1;
        }
        else
            currSubarrayStart = -1;
    }

    return subarrayCount;
}