
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k);
bool checkWindow(vector<int>& nums, int l, int k);

int main()
{
    vector<int> nums = {4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11};
    divideArray(nums, 14);

    getchar();
    return 0;
}

vector<vector<int>> divideArray(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end());

    int l = 0;
    while(l <= nums.size()-3)
    {
        if(!checkWindow(nums, l, k))
            return {};
        l += 3;
    }

    vector<vector<int>> subArrays;
    for(int i = 0; i < nums.size(); i += 3)
    {
        subArrays.push_back({nums[i], nums[i+1], nums[i+2]});
    }

    return subArrays;
}

bool checkWindow(vector<int>& nums, int l, int k)
{
    return ((nums[l+1] - nums[l] <= k) && (nums[l+2] - nums[l] <= k) && (nums[l+2] - nums[l+1] <= k));
}