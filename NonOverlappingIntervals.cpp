
#include<bits/stdc++.h>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals);

int main()
{
    vector<vector<int>> intervals = {{1,2},{1,2},{1,2}};
    cout << eraseOverlapIntervals(intervals);

    getchar();
    return 0;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) -> bool {
        return i1[0] < i2[0];
    });

    int erased = 0;
    for(int l = 0, r = 1; r < intervals.size(); ++r)
    {
        if(intervals[r][0] < intervals[l][1])
        {
            erased++;
            if(intervals[r][1] < intervals[l][1])
                l = r;
        }
        else
            l = r;
    }

    return erased;
}