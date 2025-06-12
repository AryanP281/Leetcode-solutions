
#include<bits/stdc++.h>

using namespace std;

int minimumIndex(vector<int>& nums);

int main()
{

    vector<int> nums = {1,1,1,1};
    cout << minimumIndex(nums);

    getchar();

    return 0;
}

int minimumIndex(vector<int>& nums) 
{
    const int N = nums.size();
    
    unordered_map<int,int> rightNumToFreq;
    map<int,unordered_set<int>> rightFreqToNum;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(rightNumToFreq.count(nums[i]))
        {
            auto itr = rightFreqToNum.find(rightNumToFreq[nums[i]]);
            itr->second.erase(nums[i]);
            if(itr->second.empty())
                rightFreqToNum.erase(itr);
        }
        rightNumToFreq[nums[i]]++;
        rightFreqToNum[rightNumToFreq[nums[i]]].insert(nums[i]);
    }

    unordered_map<int,int> leftNumToFreq;
    map<int,unordered_set<int>> leftFreqToNum;
    for(int i = 0; i < nums.size(); i++)
    {
        //Adding to left
        if(leftNumToFreq.count(nums[i]))
        {
            auto itr = leftFreqToNum.find(leftNumToFreq[nums[i]]);
            itr->second.erase(nums[i]);
            if(itr->second.empty())
                leftFreqToNum.erase(itr);
        }
        leftNumToFreq[nums[i]]++;
        leftFreqToNum[leftNumToFreq[nums[i]]].insert(nums[i]);

        //Removing from right
        auto itr = rightFreqToNum.find(rightNumToFreq[nums[i]]);
        itr->second.erase(nums[i]);
        if(itr->second.empty())
            rightFreqToNum.erase(itr);
        rightNumToFreq[nums[i]]--;
        rightFreqToNum[rightNumToFreq[nums[i]]].insert(nums[i]);

        //Checking if valid index
        map<int,unordered_set<int>>::iterator leftDominant = leftFreqToNum.upper_bound(floor((double)(i+1)/2.0));
        map<int,unordered_set<int>>::iterator rightDominant = rightFreqToNum.upper_bound(floor((double)(N-i-1)/2.0));
        if(leftDominant != leftFreqToNum.end() && !leftDominant->second.empty() && rightDominant != rightFreqToNum.end() && !rightDominant->second.empty())
        {
            if(*(leftDominant->second.begin()) == *(rightDominant->second.begin()))
                return i;
        }
    }

    return -1;
}