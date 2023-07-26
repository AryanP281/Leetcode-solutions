
#include<bits/stdc++.h>

using namespace std;

int findCenter(vector<vector<int>>& edges);

int main()
{
    vector<vector<int>> edges = {{1,2},{5,1},{1,3},{1,4}};
    cout << findCenter(edges);

    getchar();
    return 0;
}

int findCenter(vector<vector<int>>& edges) 
{
    int* degrees = new int[edges.size()+1]();
    for(int a = 0; a < edges.size(); ++a)
    {
        degrees[edges[a][0]-1]++;
        degrees[edges[a][1]-1]++;
    }

    for(int a = 0; a < edges.size()+1; a++)
    {
        if(degrees[a] == edges.size())
            return a+1;
    }

    delete[] degrees;   
}