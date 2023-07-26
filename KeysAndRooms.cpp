
#include<bits/stdc++.h>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms);

int main()
{
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    cout << (canVisitAllRooms(rooms) ? "TRUE" : "FALSE");

    getchar();
    return 0;
}

bool canVisitAllRooms(vector<vector<int>>& rooms) 
{
    //BFS
    bool* visited = new bool[rooms.size()]();
    visited[0] = true;
    queue<int> nodesQueue;
    nodesQueue.push(0);
    int node;
    while(!nodesQueue.empty())
    {
        node = nodesQueue.front();
        nodesQueue.pop();

        for(int edge = 0; edge < rooms[node].size(); ++edge)
        {
            if(visited[rooms[node][edge]])
                continue;

            nodesQueue.push(rooms[node][edge]);
            visited[rooms[node][edge]] = true;
        }
    }

    bool canVisitAll = true;
    for(int a = 1; a < rooms.size() && canVisitAll; ++a)
    {
        canVisitAll &= visited[a];
    }

    delete[] visited;

    return canVisitAll;
}