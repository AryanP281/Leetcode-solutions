
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections);
void tarjanSSC(int currNode, int parentNode, int* nodeIds, int* lowLink, stack<int>& stack, bool* inStack, vector<int>* adjList, vector<vector<int>>& criticalConns);

int main()
{
    vector<vector<int>> conns = {{0,1}};
    criticalConnections(2, conns);

    getchar();
    return 0;
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
{
    vector<int>* adjList = new vector<int>[n];
    for(vector<int>& edge : connections)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    int* nodeIds = new int[n]();
    int* lowLink = new int[n]();
    bool* inStack = new bool[n]();
    stack<int> tarjanStack;
    vector<vector<int>> criticalConns;
    for(int i = 0; i < n; ++i)
    {
        if(nodeIds[i] == 0)
        {
            tarjanStack.push(i);
            inStack[i] = true;
            tarjanSSC(i, i, nodeIds, lowLink, tarjanStack, inStack, adjList, criticalConns);
        }
    }

    delete[] adjList;
    delete[] nodeIds;
    delete[] lowLink;
    delete[] inStack;

    return criticalConns;
}

void tarjanSSC(int currNode, int parentNode, int* nodeIds, int* lowLink, stack<int>& stack, bool* inStack, vector<int>* adjList, vector<vector<int>>& criticalConns)
{
    static int maxNodeId = 1;

    nodeIds[currNode] = maxNodeId++;
    lowLink[currNode] = nodeIds[currNode];
    for(int i = 0; i < adjList[currNode].size(); ++i)
    {
        if(adjList[currNode][i] == parentNode)
            continue;
        
        if(nodeIds[adjList[currNode][i]] == 0)
        {
            stack.push(adjList[currNode][i]);
            inStack[adjList[currNode][i]] = true;
            tarjanSSC(adjList[currNode][i], currNode, nodeIds, lowLink, stack, inStack, adjList, criticalConns);

            lowLink[currNode] = min(lowLink[currNode], lowLink[adjList[currNode][i]]);
        }
        else if(inStack[adjList[currNode][i]])
            lowLink[currNode] = min(lowLink[currNode], lowLink[adjList[currNode][i]]);
    }

    //Checking if the current node is the start of an SCC i.e has a critical connection to parent
    if(lowLink[currNode] == nodeIds[currNode])
    {
        if(currNode != parentNode)
            criticalConns.push_back({parentNode, currNode});
        while(stack.top() != currNode)
        {
            inStack[stack.top()] = false;
            stack.pop();
        }
        stack.pop();
        inStack[currNode] = false;
    }
        
}