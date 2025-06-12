
#include<bits/stdc++.h>

using namespace std;

int shortestSubarray(vector<int>& nums, int k);

int main()
{

    vector<int> nums = {1,2};
    cout << shortestSubarray(nums, 4);

    getchar();

    return 0;
}

int shortestSubarray(vector<int>& nums, int k) 
{
    typedef pair<int64_t,int> Vec;
    
    deque<Vec> monotonousStack;
    monotonousStack.push_back(Vec(0,-1));
    int64_t currSum = 0;
    int minSubarrayLen = nums.size()+1;
    for(int i = 0; i < nums.size(); i++)
    {
        currSum += (int64_t)nums[i];
        while(monotonousStack.size() && monotonousStack.front().first <= currSum - (int64_t)k)
        {
            minSubarrayLen = min(minSubarrayLen, i-monotonousStack.front().second);
            monotonousStack.pop_front();
        }

        while(monotonousStack.size() && monotonousStack.back().first >= currSum)
            monotonousStack.pop_back();
        
        monotonousStack.push_back(Vec(currSum,i));
    }

    return minSubarrayLen == nums.size()+1 ? -1 : minSubarrayLen;
}