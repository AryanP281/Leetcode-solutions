
#include<bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);

int main()
{
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    nextGreaterElement(nums1, nums2);

    getchar();
    return 0;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    unordered_map<int,int> pos;
    for(int i = 0; i < nums1.size(); ++i)
    {
        pos[nums1[i]] = i;
    }
    
    vector<int> nextGreater(nums1.size(),-1);
    stack<int> greaterStack;

    for(int i = nums2.size()-1; i >= 0; --i)
    {
        while(!greaterStack.empty() && greaterStack.top() <= nums2[i])
            greaterStack.pop();

        unordered_map<int,int>::iterator itr = pos.find(nums2[i]);
        if(itr != pos.end() && !greaterStack.empty())
            nextGreater[itr->second] = greaterStack.top();
        greaterStack.push(nums2[i]);
    }

    return nextGreater;
}