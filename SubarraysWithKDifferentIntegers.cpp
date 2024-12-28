
#include<bits/stdc++.h>

using namespace std;

int subarraysWithKDistinct(vector<int>& nums, int k);

int main()
{

    vector<int> nums = {1,2,1,2,3};
    cout << subarraysWithKDistinct(nums,2);

    getchar();
    return 0;
}

int subarraysWithKDistinct(vector<int>& nums, int k) 
{
   unordered_map<int,int> counts;

   int lFar = 0;
   int lNear = 0;
   int r = 0;

   int subArrays = 0;
   while(r < nums.size())
   {
        counts[nums[r]]++;

        while(counts.size() > k)
        {
            counts[nums[lNear]]--;
            if(counts[nums[lNear]] == 0)
                counts.erase(nums[lNear]);
            lNear++;
            lFar = lNear;
        }

        while(counts[nums[lNear]] > 1)
        {
            counts[nums[lNear]]--;
            lNear++;
        }

        if(counts.size() == k)
            subArrays += (lNear - lFar) + 1;
        r++;
   }

   return subArrays;
}