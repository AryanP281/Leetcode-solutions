
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> findMatrix(vector<int>& nums);

int main()
{
    vector<int> nums = {1,2,3,4};
    findMatrix(nums);

    getchar();
    return 0;
}

vector<vector<int>> findMatrix(vector<int>& nums) 
{
    int* freqs = new int[nums.size()]();
    for(int i = 0; i < nums.size(); ++i)
    {
        freqs[nums[i]-1]++;
    }

    vector<vector<int>> uniqueElems;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(freqs[i] != 0)
            uniqueElems.push_back({i+1, freqs[i]});
    }

    auto sortFunc = [](vector<int>& x, vector<int>& y) -> bool {
        return x[1] > y[1];
    };
    sort(uniqueElems.begin(), uniqueElems.end(), sortFunc);

    vector<vector<int>> result(uniqueElems[0][1], vector<int>());
    for(int i = 0; i < uniqueElems.size(); ++i)
    {
        for(int r = 0; r < uniqueElems[i][1]; ++r)
        {
            result[r].push_back(uniqueElems[i][0]);
        }
    }

    delete[] freqs;

    return result;
}