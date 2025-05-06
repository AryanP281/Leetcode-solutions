#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();

    return 0;
}

int minSessions(vector<int>& tasks, int sessionTime) 
{
    const int STATE_COUNT = pow(2,tasks.size());
    int* dp = new int[STATE_COUNT];
    fill_n(dp, STATE_COUNT, -1);
    dp[STATE_COUNT-1] = 0;

    int result = getMinSessions(0, sessionTime, tasks, dp);

    delete[] dp;

    return result;
}   

int getMinSessions(int state, int sessionTime, vector<int>& tasks, int* dp)
{
    if(dp[state] != -1)
        return dp[state];

    int currTotalTime = 0;
    for(int i = 0; i < tasks.size(); ++i)
    {
        if((state & (1 << i)) != 0)
            currTotalTime += tasks[i];
    }

    int timeLeft = sessionTime - (currTotalTime % sessionTime);
    dp[state] = INT_MAX;
    for(int i = 0; i < tasks.size(); ++i)
    {
        if((state & (1 << i)) != 0)
            continue;

        if(tasks[i] > timeLeft)
            dp[state] = min(dp[state], 1+getMinSessions(state | (1 << i), sessionTime, tasks, dp));
        else
            dp[state] = min(dp[state], getMinSessions(state | (1 << i), sessionTime, tasks, dp));
    }

    return dp[state];
}