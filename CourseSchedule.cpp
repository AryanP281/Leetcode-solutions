
#include<bits/stdc++.h>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites);

int main()
{

    getchar();
    return 0;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
    unordered_set<int> zeroInDeg;
    bool** adjMatrix = new bool*[numCourses];
    for(int i = 0; i < numCourses; ++i)
    {
        adjMatrix[i] = new bool[numCourses]();
        zeroInDeg.insert(i);
    }   

    int* inDeg = new int[numCourses]();
    for(int i = 0; i < prerequisites.size(); ++i)
    {
        adjMatrix[prerequisites[i][1]][prerequisites[i][0]] = true;
        inDeg[prerequisites[i][0]]++;
        zeroInDeg.erase(prerequisites[i][0]);
    }

    bool* visitedCourses = new bool[numCourses]();
    while(!zeroInDeg.empty())
    {
        int currCourse = *zeroInDeg.begin();
        zeroInDeg.erase(currCourse);
        visitedCourses[currCourse] = true;

        for(int i = 0; i < numCourses; ++i)
        {
            if(adjMatrix[currCourse][i])
            {
                inDeg[i]--;
                if(inDeg[i] == 0)
                    zeroInDeg.insert(i);
            }
        }
    }

    bool validSchedule = true;
    for(int i = 0; i < numCourses; ++i)
    {
        validSchedule &= visitedCourses[i];
    }

    for(int i = 0; i < numCourses; ++i)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] inDeg;
    delete[] visitedCourses;

    return validSchedule;
}