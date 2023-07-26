
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker);
int binarySearch(vector<Vec>& jobs, int diff);

int main()
{
    vector<int> difficulty = {85,47,57};
    vector<int> profit = {24,66,99};
    vector<int> worker = {40,25,25};

    cout << maxProfitAssignment(difficulty, profit, worker);


    getchar();
    return 0;
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
{
        vector<Vec> jobs;
        for(int i = 0; i < difficulty.size(); ++i)
        {
            jobs.push_back(Vec(difficulty[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), [](Vec& j1, Vec& j2) -> bool {
            return j1.first < j2.first;
        });

        vector<int> maxProfits = {jobs[0].second};
        for(int i = 1; i < jobs.size(); ++i)
        {
            maxProfits.push_back(max(maxProfits[i-1], jobs[i].second));
        }

        int maxProfit = 0;
        for(int i = 0; i < worker.size(); ++i)
        {
            int pos = binarySearch(jobs, worker[i]);
            if(pos == -1)
                continue;
            
            maxProfit += maxProfits[pos];
        }

        return maxProfit;
}

int binarySearch(vector<Vec>& jobs, int diff)
{
    int l = 0;
    int r = jobs.size()-1;

    int m;
    int i = -1;
    while(l <= r)
    {
        m = (l+r)/2;
        if(jobs[m].first > diff)
            r = m-1;
        else
        {
            l = m+1;
            i = m;
        }
    }

    return i;
}