
#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices);

int main()
{
    vector<int> prices = {7,6,4,3,1};
    cout << maxProfit(prices);

    getchar();
    return 0;
}

int maxProfit(vector<int>& prices) 
{
    int* maxs = new int[prices.size()];
    maxs[prices.size()-1] = *prices.rbegin();
    for(int a = prices.size()-2; a >= 0; --a)
    {
        maxs[a] = max(maxs[a+1], prices[a]);
    }

    int maxProf = 0;
    for(int a = 0; a < prices.size(); ++a)
    {
        if(maxs[a] - prices[a] > maxProf)
            maxProf = maxs[a] - prices[a];
    }

    delete[] maxs;

    return maxProf;
}


/*
int maxProfit(vector<int>& prices)
{
    int* diffs = new int[prices.size() - 1];
    for (int a = 1; a < prices.size(); ++a)
    {
        diffs[a - 1] = prices[a] - prices[a - 1];
    }

    int maxSoFar = 0;
    int maxEndingHere = 0;
    for (int a = 0; a < prices.size() - 1; ++a)
    {
        maxEndingHere += diffs[a];
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }

    delete[] diffs;

    return maxSoFar;
}

*/