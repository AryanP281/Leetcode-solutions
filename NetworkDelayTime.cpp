
#include<bits/stdc++.h>

#define INF INT32_MAX

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k);


int main()
{
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    cout << networkDelayTime(times, 4, 2);


    getchar();
    return 0;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) 
{
    int** adjMatrix = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        adjMatrix[i] = new int[n]();
        fill_n(&adjMatrix[i][0], n, -1);
    }
    for(int i = 0; i < times.size(); ++i)
    {
        adjMatrix[times[i][0]-1][times[i][1]-1] = times[i][2];
    }

    vector<int> minDelays;
    for(int i = 0; i < n; ++i)
    {
        minDelays.push_back(INF);
    }

    minDelays[k-1] = 0;
    for(int i = 1; i <= n-1; ++i)
    {
        for(int nd = 0; nd < n; ++nd)
        {
            if(minDelays[nd] == INF)
                continue;
            
            for(int e = 0; e < n; ++e)
            {
                //No edge
                if(adjMatrix[nd][e] == -1)
                    continue;
                
                minDelays[e] = min(minDelays[e], minDelays[nd]+adjMatrix[nd][e]);
            }
        }
    }

    int minNodeDelay = 0;
    for(int i = 0; i < minDelays.size(); ++i)
    {        
        if(minDelays[i] == INF)
            return -1;

        minNodeDelay = max(minNodeDelay, minDelays[i]);
    }

    for(int i = 0; i < n; ++i)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return minNodeDelay;
}