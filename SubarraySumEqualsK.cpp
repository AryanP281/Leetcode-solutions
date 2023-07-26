
#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k);

int main()
{   
    vector<int> arr = {1,2,3};
    cout << subarraySum(arr,3);

    getchar();
    return 0;
}

int subarraySum(vector<int>& nums, int k) 
{
    unordered_map<int,int> subarraySums;
    subarraySums[0] = 1;

    int currSum = 0;
    int subarrayCount = 0;
    unordered_map<int,int>::iterator itr;
    for(int a = 0; a < nums.size(); ++a)
    {
        currSum += nums[a];
        itr = subarraySums.find(currSum - k);
        if(itr != subarraySums.end())
            subarrayCount += itr->second;

        subarraySums[currSum]++;
    }

    return subarrayCount;
}