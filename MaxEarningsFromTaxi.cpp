
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

long long maxTaxiEarnings(int n, vector<vector<int>>& rides);
ll getMaxEarnings(int i, vector<vector<int>>& rides, vector<ll>& maxEarnings);
int getNonIntersecting(int l, int r, vector<vector<int>>& rides);

int main()
{
    vector<vector<int>> rides = {{1,6,1},{3,10,2},{10,12,3},{11,12,2},{12,15,2},{13,18,1}};
    cout << maxTaxiEarnings(rides.size(), rides);

    getchar();
    return 0;
}

long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
{
    vector<ll> maxEarnings(rides.size(), -1);
    sort(rides.begin(),rides.end(), [](vector<int>&r1,vector<int>&r2) -> bool {
        return r1[0] < r2[0];
    });
    maxEarnings[rides.size()-1] = rides[rides.size()-1][1] - rides[rides.size()-1][0] + rides[rides.size()-1][2];

    return getMaxEarnings(0, rides, maxEarnings);
}

ll getMaxEarnings(int i, vector<vector<int>>& rides, vector<ll>& maxEarnings)
{
    if(maxEarnings[i] != -1)
        return maxEarnings[i];

    int nonIntersecting = getNonIntersecting(i,rides.size()-1, rides);
    if(nonIntersecting == rides.size())
        maxEarnings[i] = max((ll)(rides[i][1] - rides[i][0] + rides[i][2]), getMaxEarnings(i+1,rides,maxEarnings));
    else
        maxEarnings[i] = max(rides[i][1] - rides[i][0] + rides[i][2] + getMaxEarnings(nonIntersecting,rides,maxEarnings), getMaxEarnings(i+1,rides,maxEarnings));

    return maxEarnings[i];
}

int getNonIntersecting(int l, int r, vector<vector<int>>& rides)
{
    int intervalEnd = rides[l][1];

    int res = r+1;
    int m;
    while(l <= r)
    {
        m = (l+r) / 2;
        if(rides[m][0] < intervalEnd)
            l = m+1;
        else
        {
            res = m;
            r = m-1;
        }
    }

    return res;
}