
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals);
bool intersect(vector<int>& i1, vector<int>& i2);

int main()
{
    vector<vector<int>> i = {{{2,3},{4,5},{6,7},{8,9},{1,10}}};
    merge(i);

    getchar();
    return 0;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    /**Sorting by start time places earlier starting intervals first. Consider after sorting interval I1 comes before interval I2.
    If I1 and I2 do not intersect, then I1->end < I2->start which is the condition for non-intersection. As the intervals are sorted
    by start times, I1 will not intersect with any interval after I2 if it does not intersect with I2, since In(n>2)->start >= I2->start.
    Thus, the previous interval containing I2 has ended.**/
    
    //Sorting the intervals
    sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) -> bool
    {
        return i1[0] < i2[0];
    });

    vector<vector<int>> mergedIntervals;
    vector<int> currentInterval = {intervals[0][0], intervals[0][1]};
    for(int a = 1; a < intervals.size(); ++a)
    {
        if(intersect(currentInterval, intervals[a]))
        {
            currentInterval[0] = min(currentInterval[0], intervals[a][0]);
            currentInterval[1] = max(currentInterval[1], intervals[a][1]);
        }
        else
        {
            mergedIntervals.push_back(currentInterval);
            currentInterval[0] = intervals[a][0];
            currentInterval[1] = intervals[a][1];
        }
        
    }
    if(mergedIntervals.empty() || (mergedIntervals.rbegin()->at(0) != currentInterval[0] && mergedIntervals.rbegin()->at(1) != currentInterval[1]))
        mergedIntervals.push_back(currentInterval);

    return mergedIntervals;
}

bool intersect(vector<int>& i1, vector<int>& i2)
{
    return (i1[0] <= i2[0] && i1[1] >= i2[0]) || (i2[0] <= i1[0] && i2[1] >= i1[0]);
}