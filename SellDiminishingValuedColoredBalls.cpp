
#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& inventory, int orders);

int main()
{
    vector<int> inv = {3,5};
    cout << maxProfit(inv, 6);

    getchar();

    return 0;
}

int maxProfit(vector<int>& inventory, int orders) 
{
    const int64_t MOD = 1e9 + 7;
    const int64_t INV2 = (MOD + 1) / 2;

    map<int,int> freqs;

    for(int i = 0; i < inventory.size(); ++i) {
        freqs[inventory[i]]++;
    }
    freqs[0] = 1;

    int64_t profit = 0;

    while(orders) {
        int best = freqs.rbegin()->first;
        int nextBest = next(freqs.rbegin())->first;
        int freq = freqs.rbegin()->second;
        int range = best - nextBest;

        if((uint64_t)orders >= (uint64_t)range * (uint64_t)freq) {
            int64_t sum = ((int64_t)(best + nextBest + 1) * range) % MOD;
            int64_t additionalProfit = (((sum * INV2) % MOD) * freq) % MOD;
            profit = (profit + additionalProfit) % MOD;
            orders -= range * freq;
        } else {
            int fullRows = orders / freq;
            int remainder = orders % freq;
            int last = best - fullRows + 1;

            int64_t sum = ((int64_t)(best + last) * fullRows) % MOD;
            int64_t additionalProfit = (((sum * INV2) % MOD) * freq) % MOD;

            additionalProfit = (additionalProfit + ((int64_t)(best - fullRows) * remainder) % MOD) % MOD;
            profit = (profit + additionalProfit) % MOD;
            orders = 0;
        }

        freqs[nextBest] += freq;
        freqs.erase(prev(freqs.end()));
    }

    return profit;
}