
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

bool canAttendMeetings(vector<Interval>& intervals);

int main()
{
    vector<Interval> intervals = {Interval(9,15),Interval(5,8)};
    cout << (canAttendMeetings(intervals) ? "true" : "false");

    getchar();
    return 0;
}

bool canAttendMeetings(vector<Interval>& intervals) 
{
    sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2) -> bool{
        return i1.start < i2.start;
    });

    for(int i = 1; i < intervals.size(); ++i)
    {
        if(intervals[i].start < intervals[i-1].end)
            return false;
    }

    return true;
}