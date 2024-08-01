
#include<bits/stdc++.h>

using namespace std;

int minCostConnectPoints(vector<vector<int>>& points);
int manDist(vector<int>& p1, vector<int>& p2);

int main()
{
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << minCostConnectPoints(points);

    getchar();
    return 0;
}

int minCostConnectPoints(vector<vector<int>>& points) 
{
    auto cmp = [](vector<int>& v1, vector<int>& v2) -> bool
    {
        return v1[1] > v2[1];
    };
    
    //Creating MST
    priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> heap(cmp);
    int cost = 0;
    bool* connected = new bool[points.size()]();
    heap.push({0, 0});

    while(heap.size())
    {
        while(!heap.empty() && connected[heap.top()[0]])
        {
            heap.pop();
        }
        if(heap.empty())
            break;

        vector<int> nextNode = heap.top();
        heap.pop();

        cost += nextNode[1];
        connected[nextNode[0]] = true;

        for(int i = 0; i < points.size();++i)
        {   
            if(i == nextNode[0] || connected[i])
                continue;

            heap.push({i, manDist(points[nextNode[0]], points[i])});
        }
    }


    delete[] connected;

    return cost;
}

int manDist(vector<int>& p1, vector<int>& p2)
{
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}