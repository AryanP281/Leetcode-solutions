
#include<bits/stdc++.h>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) ;

int main()
{
    vector<vector<int>> trips = {{3,2,7},{3,7,9},{8,3,9}};
    cout << carPooling(trips, 11);

    getchar();
    return 0;
}

bool carPooling(vector<vector<int>>& trips, int capacity) 
{
    bool byStart = true;
    
    auto cmpInterval = [&byStart](vector<int>& i1, vector<int>& i2) -> bool
    {
        if(byStart)
            return i1[1] < i2[1];

        return i1[2] > i2[2];
    };

    vector<vector<int>> sortedByStart = trips;
    sort(sortedByStart.begin(), sortedByStart.end(), cmpInterval);

    byStart = false;
    vector<vector<int>>& sortedByEnd = trips;
    sort(sortedByEnd.begin(), sortedByEnd.end(), cmpInterval);

    int currCapacity = capacity;
    for(int a  = 0; a < sortedByStart.size(); ++a)
    {
        while((*(sortedByEnd.rbegin()))[2] <= sortedByStart[a][1])
        {
            currCapacity += sortedByEnd.rbegin()->operator[](0);
            sortedByEnd.pop_back();
        }

        if(currCapacity < sortedByStart[a][0])
            return false;
        currCapacity -= sortedByStart[a][0];
    }

    return true;
}