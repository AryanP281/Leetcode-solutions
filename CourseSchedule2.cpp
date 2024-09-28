
#include<bits/stdc++.h>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

int main()
{
    vector<vector<int>> prereqs = {};
    findOrder(1, prereqs);

    getchar();
    return 0;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
    vector<vector<int>> adjList;
    for(int r = 0; r < numCourses; ++r)
    {
        adjList.push_back(vector<int>());
    }

    int* inDegrees = new int[numCourses]();
    for(int i = 0; i < prerequisites.size(); ++i)
    {
        adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        inDegrees[prerequisites[i][0]]++;
    }

    vector<int> order;
    queue<int> toVisit;
    for(int i = 0; i < numCourses; ++i)
    {
        if(inDegrees[i] == 0)
            toVisit.push(i);
    }

    int visitedCount = 0;
    while(!toVisit.empty())
    {
        int curr = toVisit.front();
        toVisit.pop();
        order.push_back(curr);
        visitedCount++;

        for(int i = 0; i < adjList[curr].size(); ++i)
        {
            inDegrees[adjList[curr][i]]--;
            if(inDegrees[adjList[curr][i]] == 0)
                toVisit.push(adjList[curr][i]);
        }
    }

    delete[] inDegrees;

    if(visitedCount != numCourses)
        return {};

    return order;
}