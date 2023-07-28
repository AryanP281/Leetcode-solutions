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
    int mxProfit = 0;
    int currMin = prices[0];

    for(int i = 1; i < prices.size();++i)
    {
        mxProfit = max(mxProfit, prices[i] - currMin);
        currMin = min(currMin, prices[i]);
    }

    return mxProfit;
}