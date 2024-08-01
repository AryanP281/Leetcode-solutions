#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);

int main()
{

    getchar();
    return 0;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    if(intervals.size() == 0)
        return {newInterval};

    addInterval(newInterval, intervals);

    //Merging overlapping intervals
    vector<vector<int>> merged;
    vector<int> currInterval = intervals[0];
    for(int i = 0; i < intervals.size(); ++i)
    {
        if(intervals[i][0] <= currInterval[1])
            currInterval[1] = max(currInterval[1], intervals[i][1]);
        else
        {
            merged.push_back(currInterval);
            currInterval = intervals[i];
        }
    }
    merged.push_back(currInterval);

    return merged;
}

void addInterval(vector<int>& ni, vector<vector<int>>& intervals)
{
    int l = 0;
    int r = intervals.size()-1;
    int pos = -1;
    while(l <= r)
    {
        int m = ceil((double)(l+r)/2.0);
        if(intervals[m][0] > ni[0])
            r = m-1;
        else
        {
            pos = m;
            l = m+1;
        }
    }

    intervals.insert(intervals.begin()+pos+1, ni);
}