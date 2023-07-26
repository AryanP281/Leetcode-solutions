
#include<bits/stdc++.h>

using namespace std;

vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries);

int main()
{
    vector<int> nums = {4,5,2,2,7,10};
    vector<vector<int>> queries = {{2,3},{0,2},{0,5},{3,5}};
    vector<int> minDiffs = minDifference(nums, queries);
    for(int i = 0; i < minDiffs.size(); ++i)
    {
        cout << minDiffs[i] << ',';
    }

    getchar();
    return 0;
}

vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) 
{
    vector<int*> prefixSums(nums.size(), nullptr);
    prefixSums[0] = new int[100]();
    prefixSums[0][nums[0]-1]++;

    for(int i = 1; i < nums.size(); ++i)
    {
        prefixSums[i] = new int[100];
        for(int8_t j = 0; j < 100; ++j)
        {
            prefixSums[i][j] = prefixSums[i-1][j];
        }
        prefixSums[i][nums[i]-1]++;
    }

    vector<int> minDiffs(queries.size(), -1);
    int* prefixDiff = new int[100];
    vector<int> currNums;
    currNums.reserve(100);
    for(int i = 0; i < queries.size(); ++i)
    {
        currNums.clear();
        for(int8_t j = 0; j < 100; ++j)
        {
            int r = prefixSums[queries[i][1]][j];
            int l = prefixSums[queries[i][0]][j];
            prefixDiff[j] =  r - l  + 1*(nums[queries[i][0]] == j+1);
            if(prefixDiff[j] > 0)
                currNums.push_back(j+1);
        }
        if(currNums.size() <= 1)
            continue;

        minDiffs[i] = INT_MAX;
        for(int8_t j = 1; j < currNums.size(); ++j)
        {
            minDiffs[i] = min(minDiffs[i], abs(currNums[j] - currNums[j-1]));
        }
    }

    delete[] prefixDiff;
    for(int i = 0; i < prefixSums.size(); ++i)
    {
        delete[] prefixSums[i];
    }

    return minDiffs;
}