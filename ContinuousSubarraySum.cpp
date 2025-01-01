
#include<bits/stdc++.h>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k);

int main()
{

    vector<int> nums = {23,2,4,6,7};
    cout << checkSubarraySum(nums, 6);

    getchar();
    return 0;
}

bool checkSubarraySum(vector<int>& nums, int k) 
{
    /*S1 - S2 = xk -> (S1 - S2) MOD k = 0 -> [(S1 MOD k) - (S2 MOD k)] MOD k = 0
    As Y MOD k in [0,5], since [(S1 MOD k) - (S2 MOD k)] MOD k = 0,
    S1 MOD k = S2 MOD k.
    */

    unordered_map<int,int> mods;
    mods[0] = -1;

    int currSum = 0;
    unordered_map<int,int>::iterator itr;
    for(int i = 0; i < nums.size(); ++i)
    {
        currSum += nums[i];
        int currMod = currSum % k;
        itr = mods.find(currMod);
        if(itr != mods.end() && i - itr->second > 1)
            return true;
        else if(itr == mods.end())
            mods[currMod] = i;
    }

    return false;
}