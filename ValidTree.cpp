
#include<bits/stdc++.h>

using namespace std;

bool validTree(int n, vector<vector<int>>& edges);
bool isTree(int currNode, int parentNode, int n, bool** adjMatrix, bool* visited);

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << validTree(5, edges);

    getchar();
    return 0;
}

bool validTree(int n, vector<vector<int>>& edges) 
{
    bool* visited = new bool[n]();
    bool** adjMatrix = new bool*[n];
    for(int i = 0; i < n; ++i)
    {
        adjMatrix[i] = new bool[n]();
    }

    for(int i = 0; i < edges.size(); ++i)
    {
        adjMatrix[edges[i][0]][edges[i][1]] = true;
        adjMatrix[edges[i][1]][edges[i][0]] = true;
    }

    bool tree = isTree(0, -1, n, adjMatrix, visited);
    for(int i = 0; i < n && tree; ++i)
    {
        tree &= visited[i];
    }


    for(int i = 0; i < n; ++i)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] visited;

    return tree;
}

bool isTree(int currNode, int parentNode, int n, bool** adjMatrix, bool* visited)
{
    if(visited[currNode])
        return false;

    visited[currNode] = true;

    bool tree = true;
    for(int i = 0; i < n && tree; ++i)
    {
        if(i == parentNode || !adjMatrix[currNode][i])
            continue;
        tree = isTree(i, currNode, n, adjMatrix, visited);
    }

    return tree;
}