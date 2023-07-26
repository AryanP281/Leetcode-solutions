
#include<bits/stdc++.h>

using namespace std;

int minimumEffort(vector<vector<int>>& tasks);

int main()
{
    vector<vector<int>> tasks = {{1,2},{1,7},{2,3},{5,9},{2,2}};
    cout << minimumEffort(tasks) << '\n';

    getchar();
    return 0;
}

int minimumEffort(vector<vector<int>>& tasks) 
{
    /*Energy saved after completing a task = task[1]-task[0]. 
    The more the energy saved the more the energy availabel for the next tasks.*/
    
    sort(tasks.begin(), tasks.end(), [](vector<int>& t1, vector<int>& t2) -> bool
    {
        return (t1[1] - t1[0]) > (t2[1] - t2[0]);
    });

    int initalEnergyReq = 0;
    int currEnergyLeft = 0;
    for(int a = 0; a < tasks.size(); ++a)
    {
        if(currEnergyLeft < tasks[a][1])
        {
            initalEnergyReq += (tasks[a][1] - currEnergyLeft);
            currEnergyLeft = tasks[a][1];
        }
        currEnergyLeft -= tasks[a][0];
    }

    return initalEnergyReq;
}