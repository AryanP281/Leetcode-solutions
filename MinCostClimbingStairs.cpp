
#include<bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int>& cost);

int main()
{
    vector<int> costs = {1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(costs);

    getchar();
    return 0;
}

int minCostClimbingStairs(vector<int>& cost) 
{
    int minCosts[2] = {0,0};
    int currMinCost = 0;

    for(int i = cost.size()-1; i >= 0; --i, minCosts[1] = minCosts[0], minCosts[0] = currMinCost)
    {
        currMinCost = cost[i] + min(minCosts[0], minCosts[1]);
    }

    return min(minCosts[0], minCosts[1]);   
}