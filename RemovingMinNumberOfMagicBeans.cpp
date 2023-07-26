
#include<bits/stdc++.h>

using namespace std;

long long minimumRemoval(vector<int>& beans);

int main()
{
    vector<int> beans = {2,10,3,2};
    cout << minimumRemoval(beans);

    getchar();
    return 0;
}

long long minimumRemoval(vector<int>& beans) 
{
    sort(beans.begin(), beans.end());
    int64_t* cumSum = new int64_t[beans.size()]();
    cumSum[0] = beans[0];
    for(int i = 1; i < beans.size(); ++i)
    {
        cumSum[i] = cumSum[i-1] + beans[i];
    }

    int l, r;
    int64_t minCost = INT64_MAX;
    int64_t currCost;
    for(l = 0; l < beans.size(); l=r)
    {
        for(r = l+1; r < beans.size() && beans[r] == beans[l]; r++);

        currCost = 0;
        if(l)
            currCost = cumSum[l-1];
        if(r != beans.size())
            currCost += cumSum[beans.size()-1] - cumSum[r-1] - (beans[l] * (beans.size()-r));
        minCost = min(minCost, currCost);
    }

    delete[] cumSum;

    return minCost;
}