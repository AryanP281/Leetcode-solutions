
#include<bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};

    cout << orangesRotting(grid);

    getchar();
    return 0;
}

int orangesRotting(vector<vector<int>>& grid)
{

    const int NEIGHBOURS[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    auto twoDTo1D = [&grid](int r, int c) -> int {
        return r * grid[0].size() + c;
    };
    auto oneDTo2D = [&grid](int i) -> pair<int,int> {
        int r = floor(i / grid[0].size());
        int c = i % grid[0].size();

        return pair<int,int>(r,c);
    };

    queue<int>* currRotten = new queue<int>();
    queue<int>* nextRotten = new queue<int>();
    bool* visited = new bool[grid.size()*grid[0].size()]();
    unordered_set<int> oranges;
    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            if(grid[r][c] == 1)
                oranges.insert(twoDTo1D(r,c));
            else if(grid[r][c] == 2)
            {
                int rotten = twoDTo1D(r,c);
                currRotten->push(rotten);
                visited[rotten] = true;
            }
        }
    }

    if(oranges.empty())
        return 0;

    int currTime = -1;
    while(!currRotten->empty())
    {
        currTime++;
        while(!currRotten->empty())
        {
            int currOrange = currRotten->front();
            currRotten->pop();
            oranges.erase(currOrange);

            pair<int,int> oCoords = oneDTo2D(currOrange);
            for(int i = 0; i < 4; ++i)
            {
                int nR = oCoords.first + NEIGHBOURS[i][0];
                int nC = oCoords.second + NEIGHBOURS[i][1];

                if(nR >= 0 && nR < grid.size() && nC >= 0 && nC < grid[nR].size())
                {
                    int nO = twoDTo1D(nR,nC);
                    if(grid[nR][nC] == 1 && !visited[nO])
                    {
                        visited[nO] = true;
                        nextRotten->push(nO);
                    }
                }
            }
        }

        delete currRotten;
        currRotten = nextRotten;
        nextRotten = new queue<int>();
    }

    delete currRotten;
    delete nextRotten;
    delete[] visited;

    if(!oranges.empty())
        return -1;

    return currTime;
}