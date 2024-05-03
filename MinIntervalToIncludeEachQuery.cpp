
#include<bits/stdc++.h>

using namespace std;

vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries);

int main()
{

    vector<vector<int>> intervals = {{2,3},{2,5},{1,8},{20,25}};
    vector<int> queries = {2,19,5,22};

    minInterval(intervals, queries);

    getchar();
    return 0;
}

vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) 
{
    auto cmp = [](vector<int>& i1, vector<int>& i2) -> bool {
        return (i1[1] -i1[0]) > (i2[1] - i2[0]);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);

    sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) -> bool {
        return i1[0] < i2[0];
    });

    vector<int> orgQueries = queries;
    sort(queries.begin(), queries.end());

    int iPtr = 0;
    unordered_map<int,int> minIntervals;
    for(int j = 0; j < queries.size(); ++j)
    {
        while(iPtr < intervals.size() && intervals[iPtr][0] <= queries[j])
        {
            heap.push(intervals[iPtr++]);
        }

        while(!heap.empty() && heap.top()[1] < queries[j])
        {
            heap.pop();
        }

        if(!heap.empty())
            minIntervals[queries[j]] = (heap.top()[1] - heap.top()[0] + 1);
        else
            minIntervals[queries[j]] = -1;
    }

    vector<int> res;
    for(int i = 0; i < orgQueries.size(); ++i)
    {
        res.push_back(minIntervals[orgQueries[i]]);
    }

    return res;
}