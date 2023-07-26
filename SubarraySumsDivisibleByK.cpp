
#include<bits/stdc++.h>

using namespace std;

int subarraysDivByK(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {-1,2,9};
    cout << subarraysDivByK(nums, 2);

    getchar();
    return 0;
}

int subarraysDivByK(vector<int>& nums, int k) 
{
    int* mods = new int[k];
    mods[0] = 1;

    int subarrayCount = 0;
    int currSum = 0;
    int mod;
    for(int i = 0; i < nums.size(); ++i)
    {
        currSum += nums[i];
        mod = (currSum % k) + k*((currSum % k) < 0);
        subarrayCount += mods[mod];
        mods[mod]++;
    }

    delete[] mods;
    return subarrayCount;
}