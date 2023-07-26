
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

const Vec NEIGHBOUR_VECS[4] = {Vec(0,-1), Vec{-1,0}, Vec(0,1), Vec(1,0)};

int getMaximumGold(vector<vector<int>>& grid);
int traverseGrid(Vec currNode, vector<vector<int>>& grid, bool* visited);
queue<Vec> getNeighbours(Vec& node, Vec& gridDims);

int main()
{
    vector<vector<int>> grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    cout << getMaximumGold(grid);
    
    getchar();
    return 0;
}

int getMaximumGold(vector<vector<int>>& grid) 
{
    bool* visited = new bool[grid.size()*grid[0].size()]();

    int maxGold = 0;
    int currGold;
    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            if(grid[r][c])
            {
                currGold = traverseGrid(Vec(r,c), grid, visited);
                if(currGold > maxGold)
                    maxGold = currGold;
            }
        }
    }

    delete[] visited;

    return maxGold;
}

int traverseGrid(Vec currNode, vector<vector<int>>& grid, bool* visited)
{
    Vec gridDims(grid.size(), grid[currNode.first].size());
    visited[currNode.first*gridDims.second+currNode.second] = true;

    int maxGold = grid[currNode.first][currNode.second];
    int currGold;
    queue<Vec> neighbours = getNeighbours(currNode, gridDims);
    while(!neighbours.empty())
    {
        if(grid[neighbours.front().first][neighbours.front().second] &&
            !visited[neighbours.front().first*gridDims.second+neighbours.front().second])
        {
            currGold = grid[currNode.first][currNode.second] + traverseGrid(neighbours.front(), grid, visited);
            if(currGold > maxGold)
                maxGold = currGold;
        }

        neighbours.pop();
    }

    visited[currNode.first*gridDims.second+currNode.second] = false;

    return maxGold;
}

queue<Vec> getNeighbours(Vec& node, Vec& gridDims)
{
    queue<Vec> neighbours;
    
    for(int a = 0; a < 4; ++a)
    {
        Vec neighbourCoords(node.first + NEIGHBOUR_VECS[a].first, node.second + NEIGHBOUR_VECS[a].second);
        if(neighbourCoords.first >= 0 && neighbourCoords.first < gridDims.first && neighbourCoords.second >= 0 && 
        neighbourCoords.second < gridDims.second)
        {
            neighbours.push(neighbourCoords);
        }
    }

    return neighbours;
}