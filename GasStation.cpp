
#include<bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

int main()
{

    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};

    cout << canCompleteCircuit(gas,cost);

    getchar();
    return 0;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
    vector<int> prefixSum;
    multiset<int> minValLeft,minValRight;

    prefixSum.push_back(gas[0] - cost[0]);
    minValRight.insert(prefixSum[0]);
    for(int i = 1; i < gas.size(); ++i)
    {
        prefixSum.push_back(prefixSum[i-1] + gas[i] - cost[i]);
        minValRight.insert(prefixSum[i]);
    }

    if(*(minValRight.begin()) >= 0)
        return 0;

    int station = -1;
    minValLeft.insert(prefixSum[0]);
    minValRight.erase(prefixSum[0]);
    for(int i = 1; i < gas.size() && station == -1; minValRight.erase(prefixSum[i]), minValLeft.insert(prefixSum[i]),++i)
    {
        if((*(minValRight.begin()) - prefixSum[i-1] >= 0))
        {
            if(*(minValLeft.begin()) + *(prefixSum.rbegin()) - prefixSum[i-1] >= 0)
                station = i;
        }
    }

    return station;
}