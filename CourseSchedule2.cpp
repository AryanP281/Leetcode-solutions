/*
#include<vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

void main()
{
    vector<vector<int>> prereq;
    prereq.push_back(vector<int>());
    prereq[0].push_back(0);
    prereq[0].push_back(1);
    prereq.push_back(vector<int>());
    prereq[1].push_back(0);
    prereq[1].push_back(2);
    prereq.push_back(vector<int>());
    prereq[2].push_back(1);
    prereq[2].push_back(2);

    vector<int> order = findOrder(3, prereq);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    Uses Kahn's Topological Sort. T(n) = O(V+E)

    vector<int>* adjList = new vector<int>[numCourses]; //An adjacency list representing the graph
    int* inDegrees = new int[numCourses](); //The in-degree (i.e number of incoming edges) of the nodes
    //Creating the adjacency list and calculating the in-degrees
    for (int a = 0; a < prerequisites.size(); ++a)
    {
        inDegrees[prerequisites[a][1]]++;
        adjList[prerequisites[a][0]].push_back(prerequisites[a][1]);
    }

    queue<int> zeroDegreeNodes; //A queue containing the nodes with zero incoming edges
    //Finding the nodes with zero incoming edges
    for (int a = 0; a < numCourses; ++a)
    {
        if (inDegrees[a] == 0) zeroDegreeNodes.push(a);
    }

    //Checking if graph is cyclic. In Cyclic graphs, all nodes have atleast one incoming edge
    if (zeroDegreeNodes.empty()) return vector<int>();

    vector<int> courseOrderRev; //The course order (in reverse)
    while (!zeroDegreeNodes.empty())
    {
        int currentNode = zeroDegreeNodes.front(); //The zero-order node a the front of the queue
        zeroDegreeNodes.pop();
        courseOrderRev.push_back(currentNode); //Adding the node to the course list
        //Decreasing the in-degree of all the connected nodes by 1, as the currentNode is removed from the graph
        for (int a = 0; a < adjList[currentNode].size(); ++a)
        {
            if (--inDegrees[adjList[currentNode][a]] == 0) zeroDegreeNodes.push(adjList[currentNode][a]);
        }
    }

    //Checking if its possible to enroll for all the courses
    if (courseOrderRev.size() != numCourses) return vector<int>();

    //Reversing the courses
    vector<int> courseOrder;
    for (int a = courseOrderRev.size() - 1; a >= 0; --a)
    {
        courseOrder.push_back(courseOrderRev[a]);
    }

    delete[] adjList;
    delete[] inDegrees;
    return courseOrder;
}*/