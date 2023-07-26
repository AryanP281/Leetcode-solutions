
#include<bits/stdc++.h>

using namespace std;

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time);
int getMinTimeToComplete(int i, vector<vector<int>>& adjList, vector<int>& time, vector<int>& dp);

int main()
{
    vector<vector<int>> relations = {{1,5},{2,5},{3,5},{3,4},{4,5}};
    vector<int> time = {1,2,3,4,5};

    cout << minimumTime(5, relations, time);

    getchar();
    return 0;
}

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
{
    int* inDegrees = new int[n]();
    vector<vector<int>> adjList(n, vector<int>());
    for(int i = 0; i < relations.size(); ++i)
    {
        adjList[relations[i][1]-1].push_back(relations[i][0]-1);
        inDegrees[relations[i][0]-1]++;
    }

    vector<int> dp(n, -1);
    int minTime = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!inDegrees[i])
            minTime = max(minTime, getMinTimeToComplete(i, adjList, time, dp));
    }   


    delete[] inDegrees;

    return minTime;
}

int getMinTimeToComplete(int i, vector<vector<int>>& adjList, vector<int>& time, vector<int>& dp)
{
    if(dp[i] != -1)
        return dp[i];

    int earliestStartTime = 0;
    for(int j = 0; j < adjList[i].size(); ++j)
    {
        earliestStartTime = max(earliestStartTime, getMinTimeToComplete(adjList[i][j], adjList, time, dp));
    }
    dp[i] = earliestStartTime + time[i];

    return dp[i];
}