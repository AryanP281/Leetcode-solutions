
#include<bits/stdc++.h>

using namespace std;

int countCompleteComponents(int n, vector<vector<int>>& edges);
uint8_t isCompleteComponent(int start, int n, bool** adjMatrix, bool* visited, int* inDegree);

int main()
{
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    cout << countCompleteComponents(6, edges);

    getchar();
    return 0;
}

int countCompleteComponents(int n, vector<vector<int>>& edges) 
{
    bool** adjMatrix = new bool*[n];
    for(int i = 0; i < n; ++i)
    {
        adjMatrix[i] = new bool[n]();
    }

    bool* visited = new bool[n]();
    int* inDegree = new int[n]();

    for(int i = 0; i < edges.size(); ++i)
    {
        adjMatrix[edges[i][0]][edges[i][1]] = true;
        inDegree[edges[i][1]] += 1;
        adjMatrix[edges[i][1]][edges[i][0]] = true;
        inDegree[edges[i][0]] += 1;
    }

    int complComponents = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!visited[i])
        {
            complComponents += isCompleteComponent(i, n, adjMatrix, visited, inDegree);
        }
    }

    for(int r = 0; r < n; ++r)
    {
        delete[] adjMatrix[r];
    }
    delete[] adjMatrix;
    delete[] visited;
    delete[] inDegree;

    return complComponents;
}

uint8_t isCompleteComponent(int start, int n, bool** adjMatrix, bool* visited, int* inDegree)
{
    queue<int>* currLevel = new queue<int>();
    queue<int>* nextLevel = new queue<int>();
    currLevel->push(start);
    visited[start] = true;
    unordered_set<int> componentNodes;

    while(!currLevel->empty())
    {
        while(!currLevel->empty())
        {
            int currNode = currLevel->front();
            currLevel->pop();
            componentNodes.insert(currNode);

            for(int c = 0; c < n; ++c)
            {
                if(adjMatrix[currNode][c] && !visited[c])
                {
                    visited[c] = true;
                    nextLevel->push(c);
                }
            }
        }
        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new queue<int>();
    }

    for(unordered_set<int>::iterator itr = componentNodes.begin(); itr != componentNodes.end(); ++itr)
    {
        if(inDegree[*itr] != componentNodes.size()-1)
            return 0;
    }

    delete currLevel;
    delete nextLevel;

    return 1;
}