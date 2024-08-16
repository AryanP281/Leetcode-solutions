#include<bits/stdc++.h>

using namespace std;

void islandsAndTreasure(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> grid = {{-1,0,2147483647},{2147483647,2147483647,-1}};
    islandsAndTreasure(grid);
    
    getchar();
    return 0;
}

void islandsAndTreasure(vector<vector<int>>& grid) 
{
    typedef pair<int,int> Vec;
    
    int** minDistances = new int*[grid.size()];
    queue<Vec>* currQueue = new queue<Vec>();
    queue<Vec>* nextQueue = new queue<Vec>();
    for(int r = 0; r < grid.size(); ++r)
    {
        minDistances[r] = new int[grid[r].size()];
        for(int c = 0; c < grid[r].size(); ++c)
        {
            switch(grid[r][c])
            {
                case 0: {
                    minDistances[r][c] = 0; 
                    currQueue->push(Vec(r,c));
                };
                break;
                case INT_MAX: minDistances[r][c] = INT_MAX; break;
                default: minDistances[r][c] = -1; break;
            }
        }
    }

    const int NEIGHBOURS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while(!currQueue->empty())
    {
        while(!currQueue->empty())
        {
            Vec curr = currQueue->front();
            currQueue->pop();

            for(int i = 0; i < 4; ++i)
            {
                Vec ngh(curr.first+NEIGHBOURS[i][0], curr.second+NEIGHBOURS[i][1]);
                if(ngh.first >= 0 && ngh.first < grid.size() && ngh.second >= 0 && ngh.second < grid[0].size() && 
                minDistances[curr.first][curr.second] + 1 < minDistances[ngh.first][ngh.second])
                {
                    minDistances[ngh.first][ngh.second] = minDistances[curr.first][curr.second]+1;
                    nextQueue->push(ngh);
                }
            }
        }

        delete currQueue;
        currQueue = nextQueue;
        nextQueue = new queue<Vec>();
    }
    delete currQueue;
    delete nextQueue;

    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            grid[r][c] = minDistances[r][c];
        }
        delete[] minDistances[r];
    }
    delete[] minDistances;

}

int search(int r, int c, vector<vector<int>>& grid, int** minDistances)
{
    
}