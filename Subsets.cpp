
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums);

int main()
{
    vector<int> nums = {0};
    vector<vector<int>> subsetsVar = subsets(nums);

    for(int a = 0; a < subsetsVar.size(); ++a)
    {
        for(int b = 0; b < subsetsVar[a].size(); ++b)
        {
            cout << subsetsVar[a][b] << ' ';
        }
        cout << '\n';
    }

    getchar();
    return 0;
}

vector<vector<int>> subsets(vector<int>& nums) 
{    
    vector<vector<int>> res;
    res.reserve(pow(2, nums.size()));

    const int FINAL_BITMASK = pow(2,nums.size())-1;
    int currentBitmask = 0;
    while(currentBitmask <= FINAL_BITMASK)
    {
        vector<int> subset;
        subset.reserve(nums.size());
        for(int i = 0; i < nums.size(); ++i)
        {
            if((currentBitmask & (1 << i)) != 0)
                subset.push_back(nums[i]);
        }

        res.push_back(subset);
        ++currentBitmask;
    }

    return res;
}