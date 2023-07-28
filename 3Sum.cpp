
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main()
{
    vector<int> nums = {0,0,0};

    vector<vector<int>> triplets = threeSum(nums);

    getchar();
    return 0;
}

vector<vector<int>> threeSum(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> triplets;

    int l = 1;
    int r = nums.size()-1;
    int target;
    for(int i = 0; i < nums.size()-1;)
    {
        l = i+1;
        r = nums.size()-1;

        while(l < r)
        {
            if(nums[i] + nums[l] + nums[r] < 0)
                l++;
            else if(nums[i] + nums[l] + nums[r] > 0)
                r--;
            else
            {
                triplets.push_back({nums[i], nums[l], nums[r]});
                int oldL = l;
                int oldR = r;
                while(l < r && nums[l] == nums[oldL]) l++;
                while(l < r && nums[r] == nums[oldR]) r--;
            }
        }

        target = nums[i];
        while(i < nums.size()-1 && nums[i] == target) i++;
    }

    return triplets;
}