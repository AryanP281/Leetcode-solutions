
#include<bits/stdc++.h>

using namespace std;

int minOperations(vector<int>& nums);

int main()
{
    vector<int> nums = {2,3,3,2,2,4,2,3,4};
    cout << minOperations(nums);

    getchar();
    return 0;
}

int minOperations(vector<int>& nums) 
{
    int* minOps = new int[nums.size()+1]();
    minOps[0] = 0;
    minOps[1] = -1;
    minOps[2] = 1;

    for(int i = 3; i <= nums.size(); ++i)
    {
        minOps[i] = nums.size()+1;
        if(minOps[i - 2] != -1)
            minOps[i] = 1 + minOps[i-2];
        if(minOps[i-3] != -1)
            minOps[i] = min(minOps[i], 1 + minOps[i-3]);
        if(minOps[i-2] == -1 && minOps[i-3] == -1)
            minOps[i] = -1;
    }

    unordered_map<int,int> freqs;
    for(int i = 0; i < nums.size(); i++)
    {
        freqs[nums[i]]++;
    }

    int opsCount = 0;
    for(unordered_map<int,int>::iterator itr = freqs.begin(); itr != freqs.end(); ++itr)
    {
        if(minOps[itr->second] == -1)
            return -1;
        opsCount += minOps[itr->second];
    }

    delete[] minOps;

    return opsCount;
}