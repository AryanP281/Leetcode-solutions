
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

Vec vecs[4] = {Vec(0,1), Vec(0,-1), Vec(1,0), Vec(-1,0)};

class VecCmp 
{
public:
    bool operator()(Vec& v1, Vec& v2)
    {
        return v1.second > v2.second;
    }
};

int minCost(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> grid = {{1,2},{4,3}};
    cout << minCost(grid);

    getchar();
    return 0;
}

int minCost(vector<vector<int>>& grid) 
{
    vector<vector<Vec>> adjList(grid.size()*grid[0].size(), vector<Vec>());
    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            for(int8_t i = 0; i < 4; ++i)
            {
                Vec nPos = Vec(r+vecs[i].first, c+vecs[i].second);
                if(nPos.first >= 0 && nPos.first < grid.size() && nPos.second >= 0 && nPos.second < grid[r].size())
                {
                    adjList[r*grid[r].size()+c].push_back(Vec(nPos.first*grid[r].size()+nPos.second, 1*(grid[r][c] != i+1)));
                }
            }
        }
    }

    bool* visited = new bool[adjList.size()]();
    int* minCosts = new int[adjList.size()];
    fill_n(minCosts, adjList.size(), INT_MAX);
    minCosts[0] = 0;
    priority_queue<Vec,vector<Vec>,VecCmp> heap;
    heap.push(Vec(0,0));
    while(!visited[adjList.size()-1])
    {
        Vec curr = heap.top();
        heap.pop();

        if(curr.second != minCosts[curr.first])
            continue;
        visited[curr.first] = true;

        for(int8_t i = 0; i < adjList[curr.first].size(); ++i)
        {
            int cost = curr.second + adjList[curr.first][i].second;
            if(cost < minCosts[adjList[curr.first][i].first])
            {
                minCosts[adjList[curr.first][i].first] = cost;
                heap.push(Vec(adjList[curr.first][i].first, cost));
            }
        }
    }

    delete[] visited;
    int cost = minCosts[adjList.size()-1];
    delete[] minCosts;

    return cost;
}