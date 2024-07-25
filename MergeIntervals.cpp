#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    typedef vector<int> Int;

    auto sortFunc = [](Int& i1, Int& i2) -> bool {
        return i1[0] < i2[0];
    };
    sort(intervals.begin(), intervals.end(), sortFunc);

    vector<Int> mergedInts;
    Int currInt = intervals[0];
    for(int i = 1; i < intervals.size(); ++i)
    {
        if(intervals[i][0] <= currInt[1])
            currInt[1] = max(currInt[1], intervals[i][1]);
        else
        {
            mergedInts.push_back(currInt);
            currInt = intervals[i];
        }
    }
    mergedInts.push_back(currInt);

    return mergedInts;  
}