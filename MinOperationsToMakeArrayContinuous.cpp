
#include<bits/stdc++.h>

using namespace std;

int minOperations(vector<int>& nums);

int main()
{
    vector<int> nums = {2,3,4,5};
    cout << minOperations(nums);
    
    getchar();

    return 0;
}


int minOperations(vector<int>& nums) 
{
    set<int> unique(nums.begin(), nums.end());
    vector<int> newNums;
    for(int num : unique)
    {
        newNums.push_back(num);
    }

    int minOps = nums.size();
    for(int i = 0; i < newNums.size(); ++i)
    {
        int partner = newNums[i] + nums.size()-1;
        int partnerPos = upper_bound(newNums.begin(), newNums.end(), partner) - newNums.begin();
        minOps = min(minOps, (int)nums.size() - (partnerPos - i));
    }

    return minOps;
}

