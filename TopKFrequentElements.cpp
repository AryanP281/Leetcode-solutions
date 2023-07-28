
#include<bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 8, 8, 10, 10, 10, 11, 11,100};
    vector<int> freq = topKFrequent(nums,4);

    for(auto x : freq)
    {
        cout << x << ',';
    }

    getchar();
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) 
{
    unordered_map<int,int> freqs;
    for(int i = 0; i < nums.size(); ++i)
    {
        freqs[nums[i]] += 1;
    }

    vector<int>* freqCounts = new vector<int>[nums.size()];
    for(unordered_map<int,int>::iterator itr = freqs.begin(); itr != freqs.end(); ++itr)
    {
        freqCounts[itr->second-1].push_back(itr->first);
    }

    vector<int> topK;
    for(int i = nums.size()-1; i >= 0 && topK.size() < k; --i)
    {
        for(int j = 0; j < freqCounts[i].size() && topK.size() < k; ++j)
        {
            topK.push_back(freqCounts[i][j]);
        }
    }

    delete[] freqCounts;

    return topK;
}