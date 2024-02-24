
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums);

int main()
{

    vector<int> nums = {9,0,3,5,7};
    subsets(nums);

    getchar();
    return 0;
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    int maxState = pow(2, nums.size());

    vector<vector<int>> res;
    for(int i = 0; i < maxState; ++i)
    {
        res.push_back({});
        for(int j = 0; j < nums.size(); ++j)
        {
            if((i & (1 << j)))
                res[res.size()-1].push_back(nums[j]);
        }
    }        

    return res;
}