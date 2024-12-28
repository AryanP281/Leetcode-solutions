
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);
void kSum(int start, int k, int64_t target, vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& subsets);

int main()
{
    vector<int> nums = {-2,-1,-1,1,1,2,2};
    fourSum(nums, 0);

    getchar();
    return 0;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    sort(nums.begin(), nums.end());

    vector<int> currSubset;
    vector<vector<int>> subsets;
    kSum(0, 4, target, nums, currSubset, subsets);

    return subsets;
}

void kSum(int start, int k, int64_t target, vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& subsets)
{
    if(start >= nums.size() || (double)nums[start] > ((double)target/(double)k) || (double)(*nums.rbegin()) < ((double)target/(double)k))
        return;
    
    if(k == 2)
    {
        int l = start;
        int r = nums.size()-1;
        while(l < r)
        {
            if(l != start && nums[l] == nums[l-1])
            {
                l++;
                continue;
            }
            if(r != nums.size()-1 && nums[r] == nums[r+1])
            {
                r--;
                continue;
            }
            
            
            if(nums[l] + nums[r] == target)
            {
                currSubset.push_back(nums[l]);
                currSubset.push_back(nums[r]);
                subsets.push_back(currSubset);
                currSubset.pop_back();
                currSubset.pop_back();
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < target)
                l++;
            else
                r--;
        }
    }
    else
    {
        for(int i = start; i < nums.size(); ++i)
        {
            if(i != start && nums[i] == nums[i-1])
                continue;
            
            currSubset.push_back(nums[i]);
            kSum(i+1, k-1, target - (int64_t)nums[i], nums, currSubset, subsets);
            currSubset.pop_back();
        }
    }
}