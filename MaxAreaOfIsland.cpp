
#include<bits/stdc++.h>

using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid);
int bfs(int start, vector<vector<int>>& grid, bool* visited);

int main()
{
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << maxAreaOfIsland(grid);

    getchar();
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    bool* visited = new bool[grid.size()*grid[0].size()]();

    int maxArea = 0;
    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            int ng = r*grid[r].size() + c;
            if(grid[r][c] && !visited[ng])
                maxArea = max(maxArea, bfs(ng, grid, visited));
        }
    }

    delete[] visited;        

    return maxArea;
}

int bfs(int start, vector<vector<int>>& grid, bool* visited)
{
    const int NEIGHTBOURS[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    queue<int> bfsQueue;
    bfsQueue.push(start);
    visited[start] = true;

    int islandArea = 0;
    while(!bfsQueue.empty())
    {
        int currPos = bfsQueue.front();
        islandArea++;
        bfsQueue.pop();

        int currR = floor(currPos / grid[0].size());
        int currC = currPos % grid[0].size();
        for(int i = 0; i < 4; ++i)
        {
            int nR = currR + NEIGHTBOURS[i][0];
            int nC = currC + NEIGHTBOURS[i][1];

            if(nR >= 0 && nR < grid.size() && nC >= 0 && nC < grid[0].size())
            {
                int ng = nR*grid[0].size() + nC;
                if(grid[nR][nC] == 1 && !visited[ng])
                {
                    visited[ng] = true;
                    bfsQueue.push(ng);
                }
            }
        }
    }

    return islandArea;
}