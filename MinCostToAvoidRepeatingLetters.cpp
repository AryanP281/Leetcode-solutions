
#include<bits/stdc++.h>

using namespace std;

int minCost(string& s, vector<int>& costs);

int main()
{
    string str = "aabaa";
    vector<int> costs = {1,2,3,4,1};

    cout << minCost(str, costs);

    getchar();
    return 0;
}

int minCost(string& s, vector<int>& costs) 
{
    stack<int> prevChars;
    prevChars.push(0);

    int cost = 0;
    for(int i = 1; i < s.size(); ++i)
    {
        bool currentDeleted = false;
        while(!prevChars.empty() && !currentDeleted && s[i] == s[prevChars.top()])
        {
            if(costs[prevChars.top()] <= costs[i])
            {
                cost += costs[prevChars.top()];
                prevChars.pop();
            }
            else
            {
                cost += costs[i];
                currentDeleted = true;
            }
        }

        if(!currentDeleted)
            prevChars.push(i);
    }

    return cost;
}