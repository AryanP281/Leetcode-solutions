/*
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges);
void getAdjacencyList(vector<vector<int>>& edges, vector<int>* adjacencyList);
void bfs(vector<int>* adjList, int i, int n, bool* visited, bool* solSet);

void main()
{
    int edgeVals[5][2] = { {0,1}, {2,1}, {3,1}, {1,4}, {2,4} };
    vector<vector<int>> edges;
    for (int a = 0; a < 5; ++a)
    {
        edges.push_back(vector<int>(edgeVals[a], edgeVals[a] + 2));
    }

    vector<int> set = findSmallestSetOfVertices(5, edges);
}

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
{
    vector<int>* adjacencyList = new vector<int>[n];
    getAdjacencyList(edges, adjacencyList);
    bool* visited = new bool[n] {false};
    bool* solSet = new bool[n] {false};
    for (int a = 0; a < n; ++a)
    {
        if (visited[a]) continue;

        solSet[a] = true;
        bfs(adjacencyList, a, n, visited, solSet);
    }
    delete[] visited;
    delete[] adjacencyList;

    vector<int> sol;
    for (int a = 0; a < n; ++a)
    {
        if (solSet[a]) sol.push_back(a);
    }
    delete[] solSet;

    return sol;
}

void getAdjacencyList(vector<vector<int>>& edges, vector<int>* adjacencyList)
{
    for (int a = 0; a < edges.size(); ++a)
    {
        adjacencyList[edges[a][0]].push_back(edges[a][1]);
    }
}

void bfs(vector<int>* adjList, int i, int n, bool* visited, bool* solSet)
{
    queue<int> nodesQueue;
    nodesQueue.push(i);
    while (nodesQueue.empty() == false)
    {
        int node = nodesQueue.front();
        nodesQueue.pop();
        
        visited[node] = true;

        for (int a = 0; a < adjList[node].size(); ++a)
        {
            if (solSet[adjList[node][a]]) solSet[adjList[node][a]] = false;

            if (!visited[adjList[node][a]]) nodesQueue.push(adjList[node][a]);
        }
    }
}
*/