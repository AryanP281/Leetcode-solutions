
#include<bits/stdc++.h>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

int main()
{
    vector<vector<int>> obstacleGrid = {{0}};
    cout << uniquePathsWithObstacles(obstacleGrid);

    getchar();
    return 0;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    
    long long** dp = new long long*[obstacleGrid.size()];
    for(int r = 0; r < obstacleGrid.size(); ++r)
    {
        dp[r] = new long long[obstacleGrid[r].size()]();
    }
    dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1] = 1*(*((obstacleGrid.rbegin())->rbegin()) != 1);

    for(int r = obstacleGrid.size()-1; r >= 0; --r)
    {
        for(int c = obstacleGrid[r].size()-1-1*(r == obstacleGrid.size()-1); c >= 0; c--)
        {
            if(obstacleGrid[r][c] == 1)
                continue;
            
            if(c != obstacleGrid[r].size()-1 && obstacleGrid[r][c+1] != 1)
                dp[r][c] += dp[r][c+1];
            if(r != obstacleGrid.size()-1 && obstacleGrid[r+1][c] != 1)
                dp[r][c] += dp[r+1][c];
        }
    }

    int sol = (dp[0][0]) % (long long)1e7;
    
    for(int r = 0; r < obstacleGrid.size(); ++r)
    {
        delete[] dp[r];
    }
    delete[] dp;

    return sol;
}   
