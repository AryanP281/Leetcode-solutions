
#include<bits/stdc++.h>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
    this->start = start;
    this->end = end;
    }
};

int minMeetingRooms(vector<Interval>& intervals);

int main()
{

    vector<vector<int>> iVal = {{1,5},{5,10},{10,15},{15,20},{1,20},{2,6}};
    vector<Interval> intervals;
    for(int i = 0; i < iVal.size(); ++i)
    {
        intervals.push_back(Interval(iVal[i][0], iVal[i][1]));
    }
    cout << minMeetingRooms(intervals);

    getchar();
    return 0;
}

int minMeetingRooms(vector<Interval>& intervals) 
{
    if(intervals.size() == 0)
        return 0;
    
    sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2) -> bool {
        return i1.start < i2.start;
    });

    map<int,int> days;
    int daysCount = 1;
    days[intervals[0].end] = 1;
    for(int i = 1; i < intervals.size(); ++i)
    {
        map<int,int>::iterator day = days.upper_bound(intervals[i].start);
        if(day == days.begin())
        {
            days[intervals[i].end] = 1;
            daysCount++;
        }
        else
        {
            day = prev(day);
            day->second--;
            if(day->second == 0)
                days.erase(day);
            days[intervals[i].end]++;
        }
    }

    return daysCount;
}