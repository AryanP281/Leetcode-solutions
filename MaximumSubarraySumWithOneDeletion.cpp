/*
[1,-2,0,3]
[(1,3)]

[1,-2,-2,3]
[(1,1),(-1,3)

[-1,-1,-1,-1]
[(-,-3),(-1,-2),(-1,-1),(-1,-)]

[2,9,-4,7,-6,5,8,-5,-6,9]
[(11,14),(14,13),(21,3),(16,9)]

[1,2,-200,6,5,-1,8,-100,9]
[(3,18),(11,8),(18,9)]
*/

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int maximumSum(vector<int>& arr);
int64_t maxSubarraySum(int i, vector<int>& arr, int dir, vector<vector<int64_t>>& maxSums);

int main()
{
    vector<int> arr = {1,-2,0,3};
    cout << maximumSum(arr);

    getchar();
    return 0;
}

int maximumSum(vector<int>& arr) 
{
    vector<vector<int64_t>> maxSums(arr.size(), vector<int64_t>(2, INT64_MIN));

    for(int i = 0)
}

int64_t maxSubarraySum(int i, vector<int>& arr, int dir, vector<vector<int64_t>>& maxSums)
{
    int idx = max(dir,0);
    
    if(maxSums[i][idx] != INT64_MIN)
        return maxSums[i][idx];

    maxSums[i][idx] = INT64_MIN;
    int64_t currSum = 0;
    for(int a = i+dir; a >= 0 && a <= arr.size(); a+=dir)
    {
        if(arr[a] > 0)
        {
            currSum += arr[a];
            maxSums[i][idx] = max(maxSums[i][idx], currSum);
        }
        else
            maxSums[i][idx] = max(maxSums[i][idx], currSum + maxSubarraySum(a, arr, dir, maxSums) + arr[a]);
        
    }

    return maxSums[i][idx];
}

/*
int maximumSum(vector<int>& arr) 
{
    vector<vector<int64_t>> maxSums(arr.size(), vector<int64_t>(2, INT64_MIN));

    for(int i = 0; i < arr.size(); ++i)
    {
        maxSubarraySum(i, arr, -1, maxSums);
        maxSubarraySum(i, arr, 1, maxSums);
    }

    int64_t ans = INT64_MIN;
    for(int i = 0; i < maxSums.size(); ++i)
    {
        ans = max((int64_t)ans, maxSums[i][0]);
        ans = max((int64_t)ans, maxSums[i][1]);
        ans = max((int64_t)ans, maxSums[i][0] + maxSums[i][1]);
    }

    return ans;
}

int64_t maxSubarraySum(int i, vector<int>& arr, int dir, vector<vector<int64_t>>& maxSums)
{
    if(i < 0 || i >= arr.size())
        return 0;
    if(maxSums[i][max(dir,0)] != INT64_MIN)
        return maxSums[i][max(dir,0)];

    if(arr[i] >= 0)
        maxSums[i][max(dir,0)] = max((int64_t)arr[i], arr[i] + maxSubarraySum(i+dir, arr, dir, maxSums));
    else
        maxSums[i][max(dir,0)] = maxSubarraySum(i+dir, arr, dir, maxSums) + (arr[i+dir]*(arr[i+dir] < 0));

    return maxSums[i][max(dir,0)];
}
*/


