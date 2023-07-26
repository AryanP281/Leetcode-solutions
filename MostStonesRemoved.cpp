
#include<bits/stdc++.h>

using namespace std;

class DisjointSet
{
private :
    vector<int> parents;
    unordered_map<int,int> rootRanks;
    unordered_map<int,int> setSizes;

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
            setSizes[a] = 1;
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

            setSizes[yRoot] += setSizes[xRoot];
            setSizes.erase(xRoot);
        }
        else if(xRankItr->second > yRankItr->second)
        {
            parents[yRoot] = xRoot;
            rootRanks.erase(yRankItr);

            setSizes[xRoot] += setSizes[yRoot];
            setSizes.erase(yRoot);
        }
        else
        {
            parents[xRoot] = yRoot;
            rootRanks.erase(xRankItr);

            setSizes[yRoot] += setSizes[xRoot];
            setSizes.erase(xRoot);
        }
    }

    vector<int> getSetSizes()
    {
        vector<int> sizes(setSizes.size(), 0);
        
        int i = 0;
        for(unordered_map<int,int>::iterator itr = setSizes.begin(); itr != setSizes.end(); ++itr, ++i)
        {
            sizes[i] = itr->second;
        }

        return sizes;
    }
};

int removeStones(vector<vector<int>>& stones) ;

int main()
{
    //vector<vector<int>> stones = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    vector<vector<int>> stones = {{0,0}};
    cout << removeStones(stones);

    getchar();
    return 0;
}

int removeStones(vector<vector<int>>& stones) 
{
    DisjointSet djs(stones.size());
    
    unordered_map<int,int> colSetPtrs;
    unordered_map<int,int> rowSetPtrs;
    unordered_map<int,int>::iterator itr;
    for(int a = 0; a < stones.size(); ++a)
    {
        itr = rowSetPtrs.find(stones[a][0]);
        if(itr == rowSetPtrs.end())
            rowSetPtrs[stones[a][0]] = a;
        else
            djs.unionOp(itr->second, a);
        
        itr = colSetPtrs.find(stones[a][1]);
        if(itr == colSetPtrs.end())
            colSetPtrs[stones[a][1]] = a;
        else
            djs.unionOp(itr->second, a);
    }

    vector<int> setSizes = djs.getSetSizes();
    int stonesToRemove = 0;
    for(int a = 0; a < setSizes.size(); ++a)
    {
        stonesToRemove += setSizes[a]-1;
    }

    return stonesToRemove;
}