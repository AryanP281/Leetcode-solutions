
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
    int** maxProfits = new int*[prices.size()];
    for(int i = 0; i < prices.size(); ++i)
    {
        maxProfits[i] = new int[2];
    }

    int result = 0;
    maxProfits[0][0] = -prices[0];
    maxProfits[0][1] = 0;
    for(int i = 1; i < prices.size(); ++i)
    {
        maxProfits[i][0] = max(maxProfits[i-1][0], maxProfits[i-1][1] - prices[i]);
        maxProfits[i][1] = max(maxProfits[i][0] + prices[i], max(maxProfits[i-1][1], maxProfits[i-1][0] + prices[i]));
        result = max(result, max(maxProfits[i][0], maxProfits[i][1]));
    }

    for(int i = 0; i < prices.size(); ++i)
    {
        delete[] maxProfits[i];
    }
    delete[] maxProfits;

    return result;
}