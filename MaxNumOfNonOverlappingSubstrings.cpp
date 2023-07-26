
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

vector<string> maxNumOfSubstrings(string s);
bool isOverlapFree(vector<Vec>& intervals, Vec& interval);

int main()
{
    //string str = "abaabbcaaabbbccd";
    //string str = "deecacbacb";
    string str = "abbaccd";
    vector<string> substrs = maxNumOfSubstrings(str);
    for(string substr : substrs)
    {
        cout << substr << ' ';
    }
    
    getchar();
    return 0;
}

vector<string> maxNumOfSubstrings(string s) 
{
    Vec intervals[26];
    fill_n(intervals,26,Vec(-1,-1));
    for(int a = 0; a < s.size(); ++a)
    {
        if(intervals[s[a]-'a'].first == -1)
        {
            intervals[s[a]-'a'].first = a;
            intervals[s[a]-'a'].second = a;
        }
        else
            intervals[s[a]-'a'].second = a;
    }

    vector<Vec> substrIntervals;
    substrIntervals.reserve(s.size());

    int r;
    bool isComplete;
    for(int a = 0; a < 26; ++a)
    {
        if(intervals[a].first == -1)
            continue;

        r = intervals[a].second;
        isComplete = true;
        for(int i = intervals[a].first+1; i < r; ++i)
        {
            if(i == intervals[s[i]-'a'].first)
            {
                if(intervals[s[i]-'a'].second > r)
                    r = intervals[s[i]-'a'].second;
            }
            else if(intervals[s[i]-'a'].first < intervals[a].first)
            {
                isComplete = false;
                break;
            }
        }

        if(isComplete)
            substrIntervals.push_back(Vec(intervals[a].first, r));
    }

    sort(substrIntervals.begin(), substrIntervals.end(), [](Vec& i1, Vec& i2) -> bool {
        return (i1.second - i1.first) < (i2.second - i2.first);
    });

    vector<Vec> resultIntervals;
    resultIntervals.reserve(substrIntervals.size());
    for(int a = 0; a < substrIntervals.size(); ++a)
    {
        if(isOverlapFree(resultIntervals, substrIntervals[a]))
            resultIntervals.push_back(substrIntervals[a]);
    }

    vector<string> resSubstrs;
    resSubstrs.reserve(resultIntervals.size());
    for(int a = 0; a < resultIntervals.size(); ++a)
    {
        resSubstrs.push_back(s.substr(resultIntervals[a].first, resultIntervals[a].second - resultIntervals[a].first+1));
    }

    return resSubstrs;
}

bool isOverlapFree(vector<Vec>& intervals, Vec& interval)
{
    auto overlap = [](Vec& i1, Vec& i2) -> bool {
        return ((i1.first < i2.first && i1.second > i2.first) || (i2.first < i1.first && i2.second > i1.first));
    };

    for(int a = 0; a < intervals.size(); ++a)
    {
        if(overlap(interval, intervals[a]))
            return false;
    }

    return true;
}