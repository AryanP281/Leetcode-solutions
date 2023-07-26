
#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices);

int main()
{
    //vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    vector<int> prices = {7,6,4,3,1};
    cout << maxProfit(prices);

    getchar();
    return 0;
}

int maxProfit(vector<int>& prices) 
{
    
    int totalMaxProfit = 0;
    int currStart = 0;
    for(int a = 0; a < prices.size(); ++a)
    {
        if((a == prices.size()-1 || prices[a+1] < prices[a]) && prices[a] >= prices[currStart])
        {
            totalMaxProfit += prices[a] - prices[currStart];
            currStart = a+1;
        }
    }

    return totalMaxProfit;
}