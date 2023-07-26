/*
#include<iostream>
#include<vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost);

void main()
{
	int costVals[10] = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	vector<int> cost(costVals, costVals + 10);

	cout << minCostClimbingStairs(cost);
}

int minCostClimbingStairs(vector<int>& cost)
{
    vector<pair<int, int>> minCosts;
    minCosts.push_back(pair<int, int>(0, 0));

    /*Create table of form :-

                        0   cost[0]     cost[1]     cost[2].....
    Cost Of Skipping
    Cost Of Climbing
    

    for (int a = 0; a < cost.size(); ++a)
    {
        /*If the current step is skipped, the last step will have to be climbed. Hence,
        cost of skipping a step = cost of climbing the last step. On the other hand, if a step is climbed,
        its last step may be skipped or climbed.
        Hence, cost of climbing step = min(cost of skipping last step + cost of current step, cost of climbing
        last step + cost of current step)

        pair<int, int> vals;
        vals.first = minCosts.rbegin()->second; //Cost of skipping the step
        vals.second = min(minCosts.rbegin()->first + cost[a], minCosts.rbegin()->second + cost[a]); \\Cost of climbing step
        minCosts.push_back(vals);
    }

    return min(minCosts.rbegin()->first, minCosts.rbegin()->second);
}
*/