
#include<bits/stdc++.h>

using namespace std;

int minimizeTheDifference(vector<vector<int>>& mat, int target);
int getBestSum(int row, int target, vector<vector<int>>& mat, int** dp);

int main()
{

    vector<vector<int>> mat = {{10,3,7,7,9,6,9,8,9,5},{1,1,6,8,6,7,7,9,3,9},{3,4,4,1,3,6,3,3,9,9},{6,9,9,3,8,7,9,6,10,6}};
    cout << minimizeTheDifference(mat, 5);

    getchar();

    return 0;
}

int minimizeTheDifference(vector<vector<int>>& mat, int target) 
{
    int** dp = new int*[mat.size()];
    for(int r = 0; r < mat.size(); ++r)
    {
        dp[r] = new int[801];
        fill_n(&(dp[r][0]), 801, -1);
    }
    
    int sol = abs(target - getBestSum(0, target, mat, dp));

    for(int r = 0; r < mat.size(); ++r)
    {
        delete[] dp[r];
    }
    delete[] dp;

    return sol;
}

int getBestSum(int row, int target, vector<vector<int>>& mat, int** dp)
{
    if(row >= mat.size())
        return 0;
    else if(dp[row][target] != -1)
        return dp[row][target];
    
    int currDiff = INT_MAX;
    int currSum = 0;
    for(int c = 0; c < mat[row].size() && currDiff > 0; ++c)
    {
        currSum = mat[row][c] + getBestSum(row+1,max(0,target-mat[row][c]),mat,dp);
        if(abs(target-currSum) < currDiff)
        {
            dp[row][target] = currSum;
            currDiff = abs(target-currSum);
        }
    }

    return dp[row][target];
}