
#include<bits/stdc++.h>

using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs);

int main()
{
    vector<vector<int>> costs = {{515,563},{451,713},{537,709},{343,819},{855,779},{457,60},{650,359},{631,42}};
    cout << twoCitySchedCost(costs);

    getchar();
    return 0;
}

int twoCitySchedCost(vector<vector<int>>& costs) 
{    
    auto diff = [](vector<int>& i, vector<int>& j) -> bool
    {
        return (abs(i[0]-i[1]) > abs(j[0]-j[1]));
    };

    sort(costs.begin(), costs.end(), diff);

    int totalCost = 0;
    int countA = 0;
    int countB = 0;
    int n = costs.size()/2;
    for(int a = 0; a < costs.size(); ++a)
    {
        if(countA == n)
            totalCost += costs[a][1];
        else if(countB == n)
            totalCost += costs[a][0];
        else
        {
            if(costs[a][0] < costs[a][1])
            {
                totalCost += costs[a][0];
                countA++; 
            }
            else
            {
                totalCost += costs[a][1];
                countB++;
            }
        }
    }

    return totalCost;   
}