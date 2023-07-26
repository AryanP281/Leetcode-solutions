
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

const Vec moveVecs[4] = {Vec(0,-1), Vec(-1,0), Vec(0,1), Vec(1,0)};

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance);

int main()
{
    vector<vector<char>> maze = {{'.','+'}};
    vector<int> entrance = {0,0};

    cout << nearestExit(maze, entrance);

    getchar();
    return 0;
}

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
{
    const int rowCount = maze.size();
    const int colCount = maze[0].size();
    
    bool* visited = new bool[rowCount*colCount]();
    queue<Vec>* currLevel = new queue<Vec>();
    queue<Vec>* nextLevel = new queue<Vec>();

    visited[entrance[0]*colCount+entrance[1]] = true;
    currLevel->push(Vec(entrance[0]*colCount+entrance[1],0));

    while(!currLevel->empty())
    {
        while(!currLevel->empty())
        {
            Vec currCell = currLevel->front();
            currLevel->pop();

            Vec currCords = Vec(floor(currCell.first / colCount),currCell.first % colCount);
            for(int8_t i = 0; i < 4; ++i)
            {
                Vec moveCoords(currCords.first+moveVecs[i].first, currCords.second+moveVecs[i].second);
                if(moveCoords.first < 0 || moveCoords.first == rowCount || 
                    moveCoords.second < 0 || moveCoords.second == colCount || maze[moveCoords.first][moveCoords.second] == '+' ||
                    visited[moveCoords.first*colCount+moveCoords.second])
                    continue;
                
                if(moveCoords.second == 0 || moveCoords.first == 0 || moveCoords.second == colCount-1 || moveCoords.first == rowCount-1)
                    return currCell.second + 1;
                
                visited[moveCoords.first*colCount+moveCoords.second] = true;
                nextLevel->push(Vec(moveCoords.first*colCount+moveCoords.second, currCell.second+1));
            }
        }

        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new queue<Vec>();
    }

    delete currLevel;
    delete nextLevel;
    delete[] visited;

    return -1;
}