/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include<stdexcept>

using namespace std;

vector<int> countSort(unordered_map<int, int>& freqs, vector<int>* nums);
vector<int> topKFrequent(vector<int>& nums, int k);

void main()
{
    vector<int> nums = { 1 };

    vector<int> freq =  topKFrequent(nums, 1);
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int, int> frequencies;
    for (int a = 0; a < nums.size(); ++a)
    {
        try
        {
            int freq = frequencies.at(nums[a]);
            frequencies[nums[a]] = freq + 1;
        }
        catch (out_of_range e)
        {
            frequencies.insert(pair<int, int>(nums[a], 1));
        }
    }

    vector<int> sorted = countSort(frequencies, &nums);
    vector<int> topK;
    int lim = sorted.size() - k;
    for (int a = sorted.size() - 1; a >= lim; --a)
    {
        topK.push_back(sorted[a]);
    }

    return topK;
}

vector<int> countSort(unordered_map<int, int>& freqs, vector<int>* nums)
{
    vector<int>* freqExists = new vector<int>[nums->size()+1];
    for (auto a : freqs)
    {
        freqExists[a.second].push_back(a.first);
    }

    vector<int> sorted;
    for (int i = 0; i < nums->size()+1; ++i)
    {
        for (int j = 0; j < freqExists[i].size(); ++j)
        {
            sorted.push_back(freqExists[i][j]);
        }
    }

    delete[] freqExists;

    return sorted;
} */