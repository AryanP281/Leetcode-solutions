
#include<bits/stdc++.h>

using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {1};
    vector<int> maxWindow = maxSlidingWindow(nums, 1);
    for(auto i : maxWindow)
    {
        cout << i << ',';
    }

    getchar();
    return 0;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    map<int,int> windowVals;

    int l = 0;
    int r = 0;
    for(; r < k; ++r)
    {
        windowVals[nums[r]]++;
    }

    vector<int> maxWindow;
    maxWindow.push_back((windowVals.rbegin())->first);

    l++;
    map<int,int>::iterator itr;
    for(; r < nums.size(); ++r,l++)
    {
       itr = windowVals.find(nums[l-1]);
       itr->second--;
       if(itr->second == 0)
        windowVals.erase(itr);

       windowVals[nums[r]]++;

       maxWindow.push_back((windowVals.rbegin())->first);
    }

    return maxWindow;
}