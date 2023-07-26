
#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices);

int main()
{
    vector<int> prices = {2,1,4};
    cout << maxProfit(prices);

    getchar();
    return 0;
}

int maxProfit(vector<int>& prices) 
{
    /* maxProfits[a] = (cash at a'th day, hold at a'th day). Cash is max possible profit if stock is sold on or before day 'a'.
    Thus, cash[i] = max(profit if sold before day i, profit if sold on day i) = max(cash[i-1], hold[i]+cash).
    Hold is max possible profit if stock is owned at end of day 'a'.
    Thus, hold[i] = max(profit if bought before day i and not sold till end of i, profit if sold before i and bought on i) = 
    max(hold[i-1], cash[i-2]-prices[i]). cash[i-2] is considered for buying on day i due to the 1 day cooldown
    */
    
    if(prices.size() == 0)
        return 0;
    
    typedef pair<int,int> Vec;
    
    vector<Vec> maxProfits;
    maxProfits.reserve(prices.size());

    maxProfits.push_back(Vec(0, -prices[0]));
    Vec currMax;
    for(int a = 1; a < prices.size(); ++a)
    {
        currMax.first = max(maxProfits[a-1].first, maxProfits[a-1].second+prices[a]); //The cash profit for day 'a'
        if(a > 1)
            currMax.second = max(maxProfits[a-1].second, maxProfits[a-2].first-prices[a]); //The hold profit for day 'a'
        else
            currMax.second = max(maxProfits[a-1].second, -prices[a]);

        maxProfits.push_back(currMax);
    }

    return maxProfits.rbegin()->first;
}