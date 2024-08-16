
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

int swimInWater(vector<vector<int>>& grid) 
{
    typedef pair<int,int> Vec;

    const int NEIGHBOUR_OFFSETS[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

    auto getCoords = [&grid](int index) -> Vec
    {
        return Vec(floor(index/grid.size()), index % grid.size());
    };

    auto cmp = [&grid](Vec& v1, Vec& v2) -> bool
    {
        return v1.second > v2.second;
    };
    priority_queue<Vec,vector<Vec>,decltype(cmp)> heap(cmp);

    heap.push(Vec(0,grid[0][0]));
    bool* visited = new bool[grid.size()*grid.size()]();
    int* minTimes = new int[grid.size()*grid.size()]();
    while(visited[grid.size()*grid.size()-1] == false)
    {
        while(visited[heap.top().first])
            heap.pop();
        
        Vec currNode = heap.top();
        heap.pop();
        
        visited[currNode.first] = true;
        minTimes[currNode.first] = currNode.second;

        Vec currCoords = getCoords(currNode.first);
        for(int i = 0; i < 4; ++i)
        {
            Vec neighbourCoords = Vec(currCoords.first+NEIGHBOUR_OFFSETS[i][0],currCoords.second+NEIGHBOUR_OFFSETS[i][1]);
            
            if(neighbourCoords.first >= 0 && neighbourCoords.first < grid.size() && neighbourCoords.second >= 0 && 
            neighbourCoords.second < grid.size())
            {
                int neighbourIndex = neighbourCoords.first*grid.size() + neighbourCoords.second;
                if(!visited[neighbourIndex])
                    heap.push(Vec(neighbourIndex, max(grid[neighbourCoords.first][neighbourCoords.second], currNode.second)));
            }

        }

    }

    int minTime = minTimes[grid.size()*grid.size()-1];

    delete[] visited;
    delete[] minTimes;

    return minTime;
}