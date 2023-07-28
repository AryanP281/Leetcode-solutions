
#include<bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& nums);

int main()
{
    vector<int> nums = {3,4,5,2,66,78,77,76,79,100,80};
    cout << longestConsecutive(nums);

    getchar();
    return 0;
}

int longestConsecutive(vector<int>& nums) 
{
    unordered_set<int> seenNums;

    for(int i = 0; i < nums.size(); ++i)
    {
        seenNums.insert(nums[i]);
    } 

    int maxLen = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(seenNums.find(nums[i]) == seenNums.end())
            continue;

        int currLen = 1;
        for(int prev = nums[i]-1; seenNums.find(prev) != seenNums.end(); --prev)
        {
            currLen++;
            seenNums.erase(prev);
        }

        for(int next = nums[i] + 1; seenNums.find(next) != seenNums.end(); ++next)
        {
            currLen++;
            seenNums.erase(next);
        }

        maxLen = max(maxLen, currLen);
        seenNums.erase(nums[i]);
    }

    return maxLen;
}