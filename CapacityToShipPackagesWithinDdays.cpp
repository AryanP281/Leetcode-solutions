
#include<bits/stdc++.h>

using namespace std;

int shipWithinDays(vector<int>& weights, int D);
bool isPossible(vector<int>& weights, int capacity, int maxDays);

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};

    cout << shipWithinDays(weights, 5);

    getchar();
    return 0;
}

int shipWithinDays(vector<int>& weights, int D) 
{
    int cumSum = 0;
    int maxWeight = 0;
    for(int a = 0; a < weights.size(); ++a)
    {
        cumSum += weights[a];
        maxWeight = max(maxWeight, weights[a]);
    }

    int l = 0;
    int r = cumSum-1;
    int minCapacity = INT_MAX;
    while(l <= r)
    {
        int m = l + ((r-l) / 2.0);
        if(m+1 < maxWeight || !isPossible(weights,m+1,D))
            l = m+1;
        else
        {
            minCapacity = min(minCapacity, m+1);
            r = m-1;
        }
    }

    return minCapacity;
}

bool isPossible(vector<int>& weights, int capacity, int maxDays)
{
    int currSum = 0;
    int days = 0;
    for(int a = 0; a < weights.size() && days <= maxDays; ++a)
    {
        currSum += weights[a];
        if(currSum > capacity)
        {
            currSum = weights[a];
            ++days;
        }
    }
    days++;

    return (days <= maxDays);
}