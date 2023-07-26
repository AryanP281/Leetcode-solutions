
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int minSpaceWastedKResizing(vector<int>& nums, int k); 
int getMinSpaceWastage(int i, int k, vector<int>& nums, int** dp);

int main()
{

    vector<int> nums = {10,20,15,30,20};
    cout << minSpaceWastedKResizing(nums, 2);

    getchar();
    return 0;
}

int minSpaceWastedKResizing(vector<int>& nums, int k) 
{
    
    int** minSpaceWastage = new int*[nums.size()];
    for(int i = 0; i < nums.size(); ++i)
    {
        minSpaceWastage[i] = new int[k+1];
        fill_n(minSpaceWastage[i], k+1, -1);
    }

    int minSpace = getMinSpaceWastage(0, k, nums, minSpaceWastage);

    for(int i = 0; i < nums.size(); ++i)
    {
        delete[] minSpaceWastage[i];
    }
    delete[] minSpaceWastage;

    return minSpace;
}

int getMinSpaceWastage(int i, int k, vector<int>& nums, int** dp)
{
    if(i == nums.size())
        return 0;
    else if(k < 0)
        return INT_MAX / 2;
    else if(dp[i][k] != -1)
        return dp[i][k];

    int currMax = 0;
    int sum = 0;
    dp[i][k] = INT_MAX;
    for(int j = i; j < nums.size(); ++j)
    {
        currMax = max(currMax, nums[j]);
        sum += nums[j];

        dp[i][k] = min(dp[i][k], (currMax*(j-i+1)) - sum + getMinSpaceWastage(j+1, k-1, nums, dp));
    }

    return dp[i][k];
}