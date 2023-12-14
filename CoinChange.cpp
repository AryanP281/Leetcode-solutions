
#include<bits/stdc++.h>

using namespace std;

int coinChange(vector<int>& coins, int amount);

int main()
{

    vector<int> coins = {474,83,404,3};
    cout << coinChange(coins, 264);

    getchar();
    return 0;
}

int coinChange(vector<int>& coins, int amount) 
{
    int* minChanges = new int[amount + 1]();
    for(int i = 1; i <= amount; ++i)
    {
        minChanges[i] = amount+1;
        for(int j = 0; j < coins.size(); j++)
        {
            if(coins[j] > i)
                continue;

            minChanges[i] = min(minChanges[i], 1 + minChanges[i - coins[j]]);
        }
    }

    int change = minChanges[amount];

    delete[] minChanges;

    return change > amount ? -1 : change;
}