
#include<bits/stdc++.h>

using namespace std;

double minimumAverage(vector<int>& nums);

int main()
{
    vector<int> nums = {7,8,3,4,15,13,4,1};
    minimumAverage(nums);

    getchar();
    return 0;
}

double minimumAverage(vector<int>& nums) 
{
    multiset<int> minHeap, maxHeap;
    for(int i = 0; i < nums.size(); ++i)
    {
        minHeap.insert(nums[i]);
        maxHeap.insert(nums[i]*-1);
    }

    double minAvg = 50.0;
    
    while(minHeap.size() > 0)
    {
        int minVal = *minHeap.begin();
        int maxVal = *maxHeap.begin() * -1;
        double avg = ((double)minVal + (double)maxVal) / 2.0;

        minAvg = min(avg,minAvg);
        minHeap.erase(minHeap.begin());
        maxHeap.erase(maxHeap.begin());
    }

    return minAvg;
}