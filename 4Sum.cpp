
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec2D;

vector<vector<int>> fourSum(vector<int>& nums, int target);

int main()
{
    //vector<int> nums = {1,0,-1,0,-2,2};
    vector<int> nums = {};
    vector<vector<int>> tuples = fourSum(nums,0);

    getchar();
    return 0;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    unordered_map<int, forward_list<Vec2D>> sums;
    unordered_map<int, forward_list<Vec2D>>::iterator itr;
    for(int r = 0; r < nums.size(); ++r)
    {
        for(int c = 0; c < nums.size(); ++c)
        {
            if(c == r) continue;
            
            int sum = nums[r] + nums[c];
            itr = sums.find(sum);
            if(itr == sums.end())
            {
                forward_list<Vec2D> list = forward_list<Vec2D>();
                list.push_front(Vec2D(r,c));
                sums[sum] = list;
            }
            else
                itr->second.push_front(Vec2D(r,c));
        }
    }

    set<vector<int>> uniqueTuples;
    for(int r = 0; r < nums.size(); ++r)
    {
        for(int c = 0; c < nums.size(); ++c)
        {
            if(c == r) continue;
            
            int req = target - (nums[r]+nums[c]);
            itr = sums.find(req);
            if(itr != sums.end())
            {
                forward_list<Vec2D>::iterator listItr = itr->second.begin();
                while(listItr != itr->second.end())
                {
                    if(listItr->first != r && listItr->first != c && listItr->second != r && listItr->second != c)
                    {
                        vector<int> sortedTuple = {nums[r], nums[c], nums[listItr->first], nums[listItr->second]};
                        sort(sortedTuple.begin(), sortedTuple.end());
                        uniqueTuples.insert(sortedTuple);
                    }
                    listItr++;
                }
            }
        }
    }
 
    vector<vector<int>> tuples(uniqueTuples.begin(), uniqueTuples.end());
    return tuples;
}