
#include<bits/stdc++.h>

using namespace std;

class DisjointSet
{
private :
    vector<int> parents;
    unordered_map<int,int> rootRanks;

    void compressPath(vector<int>& path, int root)
    {
        for(int a = 0; a < path.size(); ++a)
        {
            parents[path[a]] = root;
        }
    }

public :
    DisjointSet(int nodes)
    {
        for(int a = 0; a < nodes; ++a)
        {
            parents.push_back(a);
            rootRanks[a] = 0;
        }
    }

    int find(int node)
    {
        vector<int> path;
        path.reserve(parents.size());

        int currNode = node;
        while(parents[currNode] != currNode)
        {
            path.push_back(currNode);
            currNode = parents[currNode];
        }

        compressPath(path, currNode);

        return currNode;
    }

    void unionOp(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);

        if(xRoot == yRoot)
            return;

        unordered_map<int,int>::iterator xRankItr = rootRanks.find(xRoot);
        unordered_map<int,int>::iterator yRankItr = rootRanks.find(yRoot); 

        if(xRankItr->second == yRankItr->second)
        {
            parents[xRoot] = yRoot;
            yRankItr->second++;
            rootRanks.erase(xRankItr);
        }
        else if(xRankItr->second > yRankItr->second)
        {
            parents[yRoot] = xRoot;
            rootRanks.erase(yRankItr);
        }
        else
        {
            parents[xRoot] = yRoot;
            rootRanks.erase(xRankItr);
        }
    }

    int getSetCounts() const
    {
        return rootRanks.size();
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges);

int main()
{
    vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    vector<int> redunEdge = findRedundantConnection(edges);

    cout << redunEdge[0] << ' ' << redunEdge[1];

    getchar();
    return 0;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) 
{
    DisjointSet djs(edges.size()); //Since, number of edges = (n-1+1) = n

    int parentX, parentY;
    vector<int>* redundantConnection = nullptr;
    for(int a = 0; a < edges.size(); ++a)
    {
        parentX = djs.find(edges[a][0]-1);
        parentY = djs.find(edges[a][1]-1);

        if(parentX == parentY)
            redundantConnection = &edges[a];
        else
            djs.unionOp(edges[a][0]-1, edges[a][1]-1);
    }

    return *redundantConnection;   
}