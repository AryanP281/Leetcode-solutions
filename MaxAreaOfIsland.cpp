
#include<bits/stdc++.h>

using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid);
vector<int> getNeighbours(vector<vector<int>>& grid, int node);

int main()
{
    /*vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};*/

    vector<vector<int>> grid = {{0,0,0,0,0,0,0,0}};
    cout << maxAreaOfIsland(grid);

    getchar();
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    const int n = grid.size();
    const int m = grid[0].size();
    
    int largestRegion = 0;

    bool* visited = new bool[n*m]();
    int currRegion = 0;
    stack<int> nodes;
    int node;
    for(int r = 0; r < n; ++r)
    {
        for(int c = 0; c < m; ++c)
        {
            if(visited[(r*m)+c] || grid[r][c] == 0)
                continue;

            nodes.push((r*m)+c);
            visited[(r*m)+c] = true;
            currRegion = 0;
            while(!nodes.empty())
            {
                node = nodes.top();
                nodes.pop();
                currRegion++;

                vector<int> neighbours = getNeighbours(grid,node);
                for(int a = 0; a < neighbours.size(); ++a)
                {
                    if(visited[neighbours[a]])
                        continue;

                    nodes.push(neighbours[a]);
                    visited[neighbours[a]] = true;
                }
            }
            if(currRegion > largestRegion)
                largestRegion = currRegion;
        }
    }

    delete[] visited;

    return largestRegion;
}

vector<int> getNeighbours(vector<vector<int>>& grid, int node)
{
    const int NEIGHBOUR_VECS[8][2] = {{0,-1},{-1,0},{0,1},{1,0}};

    vector<int> neighbours;

    int nodeX = node / grid[0].size();
    int nodeY = node % grid[0].size();
    int neighbourX,neighbourY;
    for(int a = 0; a < 8; ++a)
    {
        neighbourX = nodeX + NEIGHBOUR_VECS[a][0];
        neighbourY = nodeY + NEIGHBOUR_VECS[a][1];

        if(neighbourX >= 0 && neighbourX < grid.size() && neighbourY >= 0 && neighbourY < grid[0].size() && grid[neighbourX][neighbourY] == 1)
                neighbours.push_back((neighbourX*grid[0].size())+neighbourY);
    }

    return neighbours;
}

