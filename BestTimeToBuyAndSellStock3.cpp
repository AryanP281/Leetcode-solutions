
#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices);
pair<int,pair<int,int>> getMaxProfitAndInterval(vector<int>& prices, int l, int r);

int main()
{
    vector<int> prices = {6,1,3,2,4,7};
    cout << maxProfit(prices);

    getchar();
    return 0;
}

int maxProfit(vector<int>& prices) 
{
    vector<int> maxProfitRight;
    maxProfitRight.reserve(prices.size());
    maxProfitRight.push_back(0);
    int currMax = prices[prices.size()-1];
    for(int a = prices.size() - 2; a >= 0; --a)
    {
        if(prices[a] > currMax)
            currMax = prices[a];

        maxProfitRight.push_back(max(currMax - prices[a], *maxProfitRight.rbegin()));
    }
    
    vector<int> maxProfitLeft;
    maxProfitLeft.reserve(prices.size());
    maxProfitLeft.push_back(0);
    int currMin = prices[0];
    for(int a = 1; a < prices.size(); ++a)
    {
        if(prices[a] < currMin)
            currMin = prices[a];
        maxProfitLeft.push_back(max(prices[a] - currMin, *maxProfitLeft.rbegin()));
    }

    int totalMaxProfit = 0;
    int currProfit;
    for(int a = 0; a < prices.size(); ++a)
    {
        currProfit = maxProfitLeft[a] + maxProfitRight[prices.size()-1-a];
        if(currProfit > totalMaxProfit)
            totalMaxProfit = currProfit;
    }

    return totalMaxProfit;
}
