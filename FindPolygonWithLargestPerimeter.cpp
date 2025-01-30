
#include<bits/stdc++.h>

using namespace std;

long long largestPerimeter(vector<int>& nums);

int main()
{

    vector<int> nums = {5,5,50};
    cout << largestPerimeter(nums);

    getchar();
    return 0;
}

long long largestPerimeter(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());

    long long* prefixSum = new long long[nums.size()];
    prefixSum[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i)
    {
        prefixSum[i] = prefixSum[i-1]+nums[i];
    }

    long long result = -1;
    for(int i = nums.size()-1; i > 0 && result == -1; --i)
    {
        if(prefixSum[i-1] > nums[i])
            result = prefixSum[i-1] + nums[i];
    }

    delete[] prefixSum;

    return result;        
}