
#include<bits/stdc++.h>

using namespace std;

const int NEIGHBOURS[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);
void bfs(int r, int c, vector<vector<int>>& heights, uint8_t** visited, uint8_t mask);

int main()
{
    vector<vector<int>> heights = {{1}};
    pacificAtlantic(heights);


    getchar();
    return 0;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
{
    uint8_t** visited = new uint8_t*[heights.size()];
    for(int i = 0; i < heights.size(); ++i)
    {
        visited[i] = new uint8_t[heights[i].size()]();
    }

    for(int r = 0; r < heights.size(); r += max(1,(int)heights.size()-1))
    {
        int mask = (r == 0) | ((r == heights.size()-1) << 1);
        for(int c = 0; c < heights[r].size();++c)
        {
            bfs(r,c,heights,visited,mask);
        }
    }

    for(int c = 0; c < heights[0].size(); c += max(1,(int)heights[0].size()-1))
    {
        int mask = (c == 0) | ((c == heights[0].size()-1) << 1);
        for(int r = 0; r < heights.size(); ++r)
        {
            bfs(r,c,heights,visited,mask);
        }
    }

    vector<vector<int>> result;
    for(int r = 0; r < heights.size(); ++r)
    {
        for(int c = 0; c < heights[r].size(); ++c)
        {
            if(visited[r][c] == 3)
                result.push_back({r,c});
        }
    }


    for(int r = 0; r < heights.size(); ++r)
    {
        delete[] visited[r];
    }
    delete[] visited;

    return result;
}

void bfs(int r, int c, vector<vector<int>>& heights, uint8_t** visited, uint8_t mask)
{
    queue<int*>* currLevel = new queue<int*>();
    queue<int*>* nextLevel = new queue<int*>();
    currLevel->push(new int[2]);
    currLevel->front()[0] = r;
    currLevel->front()[1] = c;
    visited[r][c] |= mask;

    while(!currLevel->empty())
    {
        while(!currLevel->empty())
        {
            int* currCoords = currLevel->front();
            currLevel->pop();

            for(int i = 0; i < 4; ++i)
            {
                int nR = currCoords[0] + NEIGHBOURS[i][0];
                int nC = currCoords[1] + NEIGHBOURS[i][1];
                if(nR >= 0 && nR < heights.size() && nC >= 0 && nC < heights[nR].size())
                {
                    if(heights[nR][nC] >= heights[currCoords[0]][currCoords[1]] && (visited[nR][nC] & mask) == 0)
                    {
                        int* ngh = new int[2];
                        ngh[0] = nR;
                        ngh[1] = nC;

                        nextLevel->push(ngh);
                        visited[nR][nC] |= mask;
                    }
                }
            }
            delete[] currCoords;
        }

        currLevel = nextLevel;
        nextLevel = new queue<int*>();
    }

    delete currLevel;
    delete nextLevel;
}