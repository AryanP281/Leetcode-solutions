
#include<bits/stdc++.h>

using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph);
int8_t checkIsSafe(int node, vector<vector<int>>& adjList, int8_t* isSafe, bool* visited);

int main()
{

    vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    vector<int> safeNodes = eventualSafeNodes(graph);

    for(int node : safeNodes)
    {
        cout << node << ", ";
    }

    getchar();
    return 0;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
{
    int8_t* isSafe = new int8_t[graph.size()];
    fill_n(isSafe,graph.size(),-1);

    bool* visited = new bool[graph.size()]();
    for(int a = 0; a < graph.size(); ++a)
    {
        if(isSafe[a] != -1)
            continue;

        checkIsSafe(a, graph, isSafe, visited);
    }

    vector<int> safeNodes;
    safeNodes.reserve(graph.size());
    for(int a = 0; a < graph.size(); ++a)
    {
        if(isSafe[a] == 1)
            safeNodes.push_back(a);
    }

    delete[] isSafe;
    delete[] visited;

    return safeNodes;
}

int8_t checkIsSafe(int node, vector<vector<int>>& adjList, int8_t* isSafe, bool* visited)
{
    if(visited[node])
        return false;
    else if(isSafe[node] != -1)
        return isSafe[node];

    visited[node] = true;
    isSafe[node] = 1;
    for(int a = 0; a < adjList[node].size() && isSafe[node]; ++a)
    {
        isSafe[node] &= checkIsSafe(adjList[node][a], adjList, isSafe, visited);
    }

    visited[node] = false;

    return isSafe[node];
}