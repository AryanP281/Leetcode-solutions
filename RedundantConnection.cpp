
#include<bits/stdc++.h>

using namespace std;

class DisjointSet
{
private:
    int* roots;
    int* heights;

    int getRoot(int node)
    {
        if(roots[node] == node)
            return node;
        
        int root = getRoot(roots[node]);
        roots[node] = root;

        return root;
    }

public:
    DisjointSet(int n)
    {
        roots = new int[n];
        heights = new int[n];

        for(int i = 0; i < n; ++i)
        {
            roots[i] = i;
            heights[i] = 1;
        }
    }

    ~DisjointSet()
    {
        delete[] roots;
        delete[] heights;
    }

    void merge(int s1, int s2)
    {
       int s1Root = getRoot(s1);
       int s2Root = getRoot(s2);

       if(heights[s1Root] > heights[s2Root])
        roots[s2Root] = s1Root;
       else if(heights[s1Root] < heights[s2Root])
        roots[s1Root] = s2Root;
       else
       {
         roots[s2Root] = s1Root;
         heights[s1Root]++;
       }
    }

    int find(int node)
    {
        return getRoot(node);
    }

};

vector<int> findRedundantConnection(vector<vector<int>>& edges);

int main()
{

    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> e = findRedundantConnection(edges);
    cout << e[0] << "->" << e[1] << endl;

    getchar();
    return 0;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) 
{
    vector<int> edgeToRemove(2, 0);

    DisjointSet djs(edges.size()+1);
    for(int i = 0; i < edges.size(); ++i)
    {
        if(djs.find(edges[i][0]) == djs.find(edges[i][1]))
            edgeToRemove = edges[i];
        else
            djs.merge(edges[i][0], edges[i][1]);
    }

    return edgeToRemove;        
}