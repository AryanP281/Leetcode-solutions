
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges);
//vector<vector<int>>* getShortestPaths(vector<vector<int>>& adjList);
Vec dfs(int currNode, int parentNode, vector<vector<int>>& adjList, int* mask);

int main()
{
    vector<vector<int>> edges = {{1,9},{2,8},{2,11},{3,8},{4,6},{4,9},{5,10},{6,7},{9,10},{9,11}};
    vector<int> res = countSubgraphsForEachDiameter(11,edges);

    for(int a : res)
    {
        cout << a << ", ";
    }

    getchar();
    return 0;
}

vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) 
{
    vector<vector<int>> adjList = vector<vector<int>>(n, vector<int>());
    for(int i = 0; i < edges.size(); ++i)
    {
        adjList[edges[i][0]-1].push_back(edges[i][1]-1);
        adjList[edges[i][1]-1].push_back(edges[i][0]-1);
    }

    vector<int> res = vector<int>(n-1,0);

    int combs = pow(2,n) - 1;
    int currMaxDistance, tempMask;
    int8_t bit;
    for(int mask = 1; mask <= combs; ++mask)
    {
        if((mask & (mask-1)) == 0)
            continue;
        
        for(bit = 0; bit < n; ++bit)
        {
            if(mask & (1 << bit))
                break;
        }

        tempMask = mask;
        currMaxDistance = dfs(bit, bit, adjList, &tempMask).second;
        if(tempMask == (1 << bit))
            res[currMaxDistance-1]++;
    }

    return res;
}

Vec dfs(int currNode, int parentNode, vector<vector<int>>& adjList, int* mask)
{
    Vec maxHeightAndDistance(0,0);

    int mh1 = 0;
    int mh2 = 0;
    Vec subtreeDistAndHeight;
    for(int a = 0; a < adjList[currNode].size(); ++a)
    {
        if(adjList[currNode][a] == parentNode)
            continue;

        if((*mask & (1 << adjList[currNode][a])))
        {
            subtreeDistAndHeight = dfs(adjList[currNode][a], currNode, adjList, mask);
            if(subtreeDistAndHeight.first > mh1)
            {
                mh2 = mh1;
                mh1 = subtreeDistAndHeight.first;
            }
            else if(subtreeDistAndHeight.first > mh2)
                mh2 = subtreeDistAndHeight.first;

            maxHeightAndDistance.second = max(maxHeightAndDistance.second, subtreeDistAndHeight.second);
            *mask ^= (1 << adjList[currNode][a]);
        }
    }

    maxHeightAndDistance.first = mh1+1;
    maxHeightAndDistance.second = max(mh1+mh2, maxHeightAndDistance.second);

    return maxHeightAndDistance;
}

