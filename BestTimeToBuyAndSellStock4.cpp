
#include<bits/stdc++.h>

using namespace std;

int maxProfit(int k, vector<int>& prices);

int main()
{
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    cout << maxProfit(2,prices);

    getchar();
}

int maxProfit(int k, vector<int>& prices) 
{
    vector<vector<int>> lookupTable(prices.size(),vector<int>(k+1,0));

    int prevDiff = 0;
    for(int c = 1; c < k+1; ++c)
    {
        prevDiff = INT_MIN;
        for(int r = 1; r < prices.size(); ++r)
        {
            prevDiff = max(prevDiff, lookupTable[r-1][c-1] - prices[r-1]);
            lookupTable[r][c] = max(lookupTable[r-1][c], prices[r]+prevDiff);
        }
    }

    return lookupTable[prices.size()-1][k];
}