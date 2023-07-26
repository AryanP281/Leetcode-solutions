
#include<bits/stdc++.h>

using namespace std;

vector<int> getMaximumXor(vector<int>& nums, int maximumBit);

int main()
{
    vector<int> nums = {0,1,2,2,5,7};
    int maxBit = 3;
    vector<int> res = getMaximumXor(nums, maxBit);

    for(auto r : res)
    {
        cout << (int)r << ',';
    }

    getchar();
    return 0;
}

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
{
    uint32_t netXor = nums[0];
    for(int i = 1; i < nums.size(); ++i)
    {
        netXor ^= nums[i];
    }   

    uint32_t mask = 0xFFFFFFFF;
    mask >>= (32 - maximumBit);

    vector<int> res;
    for(int i = nums.size()-1; i >= 0; --i)
    {
        res.push_back((uint32_t)((~netXor) & (mask)));
        netXor ^= nums[i];
    }

    return res;
}