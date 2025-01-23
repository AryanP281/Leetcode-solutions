
#include<bits/stdc++.h>

using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums);

int main()
{
    vector<int> nums = {1,4,6,8,10};
    getSumAbsoluteDifferences(nums);

    getchar();
    return 0;
}

vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
{
    int prefixSum = 0;
    int suffixSum = accumulate(nums.begin(),nums.end(),0);

    vector<int> result;
    for(int i = 0; i < nums.size(); ++i)
    {
        prefixSum += nums[i];
        suffixSum -= nums[i];

        result.push_back((nums[i]*(i+1) - prefixSum) + (suffixSum - nums[i]*(nums.size()-1-i)));
    }

    return result;
}