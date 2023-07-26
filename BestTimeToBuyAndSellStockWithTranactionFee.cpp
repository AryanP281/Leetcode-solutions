
#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices, int fee);

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << maxProfit(prices, 2);

    getchar();
    return 0;
}

int maxProfit(vector<int>& prices, int fee) 
{
    /*For any day i, let cash be the max profit possible if stock is not owned at the end of the day. Thus, the stock has either
    been sold before day i and not bought again or the stock is owned at the start of day i and sold on i.
    Let hold be the max profit possible if stock is owned at the end of day i. Thus, the stock was already bought before i and
    not sold on i or the stock was not owned before i and bought on i.*/
    
    int cash = 0;
    int hold = -prices[0];

    for(int a = 1; a < prices.size(); ++a)
    {
        cash = max(cash, hold+(prices[a]-fee));
        hold = max(hold, cash-prices[a]);
    }

    return cash; 
}

/*
int maxProfit(vector<int>& prices, int fee) 
{
    const int n = prices.size();

    int* maxProfits = new int[n+1]();
    int newProfit;
    for(int i = n-2; i >= 0; --i)
    {
        maxProfits[i] = maxProfits[i+1];
        for(int j = i+1; j < n; ++j)
        {
            if(prices[j] <= prices[i])
                continue;

            newProfit = (prices[j] - prices[i] - fee) + maxProfits[j+1];
            if(newProfit > maxProfits[i])
                maxProfits[i] = newProfit;
        }
    }

    int profit = maxProfits[0];

    delete[] maxProfits;

    return profit;   
}
*/