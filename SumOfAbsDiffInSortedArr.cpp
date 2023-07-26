
#include<bits/stdc++.h>

using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums);

int main()
{
    vector<int> nums = {1,4,6,8,10};
    vector<int> res = getSumAbsoluteDifferences(nums);

    for(int a = 0; a < res.size(); ++a)
    {
        cout << res[a] << ' ';
    }

    getchar();
    return 0;
}

vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
{
    //res[i] = ((nums[i]*i) - prefixSums[i-1]) + ((totalSum - prefixSum[i-1])-(nums[i]*(n-i)))
    
    int n = nums.size();
    int* prefixSums = new int[n];
    prefixSums[0] = nums[0];
    for(int a = 1; a < n; ++a)
    {
        prefixSums[a] = prefixSums[a-1] + nums[a];
    }

    vector<int> res(n,0);
    res[0] = prefixSums[n-1]-(nums[0]*n);
    res[n-1] = (nums[n-1]*(n-1)) - prefixSums[n-2];
    for(int a = 1; a < n-1; ++a)
    {
        res[a] = ((nums[a]*a) - prefixSums[a-1]) + ((prefixSums[n-1]-prefixSums[a-1]) - (nums[a] * (n-a)));
    }

    delete[] prefixSums;

    return res;   
}