
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int countPyramids(vector<vector<int>>& grid);
int getPyramidsCount(Vec coords, vector<vector<int>>& grid, vector<vector<int>>& dp);
int getInversePyramidCount(Vec coords, vector<vector<int>>& grid, vector<vector<int>>& dp);

int main()
{
    vector<vector<int>> grid = {{1,1,1,1,0},{1,1,1,1,1},{1,1,1,1,1},{0,1,0,0,1}};
    cout << countPyramids(grid);

    getchar();
    return 0;
}

int countPyramids(vector<vector<int>>& grid) 
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));

    int pyramidCount = 0;
    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            pyramidCount += max(0, getPyramidsCount(Vec(r,c), grid, dp));
        }
    }

    dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(),-1));
    
    int inversePyramidCount = 0;
    for(int r = grid.size()-1; r >= 0; --r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            inversePyramidCount += max(0, getInversePyramidCount(Vec(r,c), grid, dp));
        }
    }

    return pyramidCount + inversePyramidCount;
}

int getPyramidsCount(Vec coords, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    if(coords.first >= grid.size() || coords.second >= grid[coords.first].size() || coords.second < 0 || 
    grid[coords.first][coords.second] == 0)
        return -1;
    if(dp[coords.first][coords.second] != -1)
        return dp[coords.first][coords.second];

    if(coords.first == grid.size() - 1 || grid[coords.first+1][coords.second] != 1)
        dp[coords.first][coords.second] = 0;
    else
    {
        dp[coords.first][coords.second] = min(getPyramidsCount(Vec(coords.first+1,coords.second-1), grid, dp), 
        getPyramidsCount(Vec(coords.first+1, coords.second+1), grid, dp)) + 1;
    }

    return dp[coords.first][coords.second];
}

int getInversePyramidCount(Vec coords, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    if(coords.first < 0 || coords.second >= grid[coords.first].size() || coords.second < 0 || grid[coords.first][coords.second] == 0)
        return -1;
    if(dp[coords.first][coords.second] != -1)
        return dp[coords.first][coords.second];

    if(coords.first == 0 || grid[coords.first-1][coords.second] != 1)
        dp[coords.first][coords.second] = 0;
    else
    {
        dp[coords.first][coords.second] = min(getInversePyramidCount(Vec(coords.first-1,coords.second-1), grid, dp), 
        getInversePyramidCount(Vec(coords.first-1, coords.second+1), grid, dp)) + 1;
    }

    return dp[coords.first][coords.second];
}