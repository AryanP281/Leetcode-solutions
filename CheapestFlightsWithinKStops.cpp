
#include<bits/stdc++.h>

using namespace std;

typedef pair<bool,int> Vec;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k);

int main()
{
    vector<vector<int>> flights = {{0,3,3},{3,4,3},{4,1,3},{0,5,1},{5,1,100},{0,6,2},{6,1,100},{0,7,1},{7,8,1},{8,9,1},{9,1,1},{1,10,1},{10,2,1},{1,2,100}};
    cout << findCheapestPrice(11, flights, 0, 2, 4);

    getchar();
    return 0;
}


int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
{
    vector<int>* currMinCosts = new vector<int>(n, 1e7);
    (*currMinCosts)[src] = 0;
    vector<int>* nextMinCosts = new vector<int>(currMinCosts->begin(), currMinCosts->end());

    for(int i = 0; i <=k; ++i)
    {
        for(int j = 0; j < flights.size(); ++j)
        {
            if((*nextMinCosts)[flights[j][1]] > (*currMinCosts)[flights[j][0]] + flights[j][2])
                (*nextMinCosts)[flights[j][1]] = (*currMinCosts)[flights[j][0]] + flights[j][2];
        }

        delete currMinCosts;
        currMinCosts = nextMinCosts;
        nextMinCosts = new vector<int>(currMinCosts->begin(), currMinCosts->end());
    }

    int res = (*currMinCosts)[dst] == 1e7 ? -1 : (*currMinCosts)[dst];
    delete currMinCosts;
    delete nextMinCosts;

    return res;
}
