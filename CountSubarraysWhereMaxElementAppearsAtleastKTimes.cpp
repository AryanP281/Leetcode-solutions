#include <bits/stdc++.h>

using namespace std;

long long countSubarrays(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {1,4,2,1};
    cout << countSubarrays(nums, 3);

    getchar();
    return 0;
}

long long countSubarrays(vector<int>& nums, int k) 
{
    int maxElement = nums[0];
    for(int i = 1; i < nums.size(); ++i)
    {
        maxElement = max(maxElement, nums[i]);
    }

    deque<int> maxOccrs;
    long long subarrayCount = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == maxElement)
            maxOccrs.push_back(i);

        if(maxOccrs.size() < k)
            continue;

        while(maxOccrs.size() > k)
            maxOccrs.pop_front();

        subarrayCount += maxOccrs.front() + 1;
    }

    return subarrayCount;
}