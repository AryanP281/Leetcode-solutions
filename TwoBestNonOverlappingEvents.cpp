
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int maxTwoEvents(vector<vector<int>>& events);
int getNonOverlappingMaxValue(vector<Vec>& maxValues, int s);

int main()
{
    vector<vector<int>> events = {{1,5,3},{1,5,1},{6,6,5}};
    cout << maxTwoEvents(events);

    getchar();
    return 0;
}

int maxTwoEvents(vector<vector<int>>& events) 
{
    sort(events.begin(), events.end(), [](vector<int>& e1, vector<int>& e2) -> bool {
        return e1[1] < e2[1];
    });

    vector<Vec> maxValues = {Vec(0,0)};
    for(int i = 0; i < events.size(); ++i)
    {
        if(maxValues.rbegin()->first == events[i][1])
            maxValues.rbegin()->second = max(maxValues.rbegin()->second, events[i][2]);
        else 
            maxValues.push_back(Vec(events[i][1], max(maxValues.rbegin()->second, events[i][2])));
    }

    int maxValue = events[0][2];
    for(int i = 0; i < events.size(); ++i)
    {
        maxValue = max(maxValue, getNonOverlappingMaxValue(maxValues, events[i][0]) + events[i][2]);
    }

    return maxValue;
}

int getNonOverlappingMaxValue(vector<Vec>& maxValues, int s)
{
    int l = 0;
    int r = maxValues.size() - 1;

    int value = 0;
    while(l <= r)
    {
        int mid = floor((l+r) / 2);

        if(maxValues[mid].first < s)
        {
            value = maxValues[mid].second;
            l = mid+1;
        }
        else
            r = mid - 1;
    }

    return value;
}
