
#include<bits/stdc++.h>

using namespace std;

int closestMeetingNode(vector<int>& edges, int node1, int node2);
void getDistances(int node, vector<int>& edges, int* distances, bool* visited);

int main()
{
    vector<int> edges = {5,3,1,0,2,4,5};
    int nodes[] = {3,2};

    cout << closestMeetingNode(edges, nodes[0], nodes[1]);

    getchar();
    return 0;
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) 
{
    int* distances = new int[edges.size()]();
    bool** visited = new bool*[2];
    visited[0] = new bool[edges.size()]();
    visited[0][node1] = true;
    visited[1] = new bool[edges.size()]();
    visited[1][node2] = true;

    getDistances(node1, edges, distances, visited[0]);
    getDistances(node2, edges, distances, visited[1]);

    int minDistance = INT32_MAX;
    int minNode = -1;
    for(int i = 0; i < edges.size(); ++i)
    {
        if(!visited[0][i] || !visited[1][i])
            continue;

        if(minDistance > distances[i])
        {
            minDistance = min(minDistance, distances[i]);
            minNode = i;
        }
    }

    delete[] distances;
    delete[] visited[0];
    delete[] visited[1];
    delete[] visited;

    return minNode;
}

void getDistances(int node, vector<int>& edges, int* distances, bool* visited)
{
    queue<int>* currLevel = new queue<int>();
    currLevel->push(node);
    queue<int>* nextLevel = new queue<int>();

    int* traversedDist = new int[edges.size()]();
    traversedDist[node] = 0;

    while(!currLevel->empty())
    {
        while(!currLevel->empty())
        {
            int currNode = currLevel->front();
            currLevel->pop();

            if(edges[currNode] != -1 && !visited[edges[currNode]])
            {
                traversedDist[edges[currNode]] = traversedDist[currNode] + 1;
                distances[edges[currNode]] = max(traversedDist[edges[currNode]], distances[edges[currNode]]);
                nextLevel->push(edges[currNode]);
                visited[edges[currNode]] = true;
            }
        }

        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new queue<int>();
    }
    delete currLevel;
    delete nextLevel;
    delete[] traversedDist;
}