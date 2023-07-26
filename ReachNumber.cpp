
#include<bits/stdc++.h>

using namespace std;

int reachNumber(int target);
int getSteps(int target);

int main()
{
    cout << reachNumber(-1000000000);

    getchar();
    return 0;
}

int reachNumber(int target) 
{
    target = abs(target);
    int steps = getSteps(target);
    int64_t sum = (steps*(steps+1)) / 2;
    int64_t delta = sum - target;

    if(delta % 2 == 0)
        return steps;
    else if(steps % 2)
        return steps+2;
    
    return steps+1;
}

int getSteps(int target)
{
    int64_t sum = 0;
    int l = 0;
    int r = target;
    int minSteps = INT_MAX;
    while(l <= r)
    {
        int m = ceil((l+r) / 2);
        sum = ((int64_t)m*((int64_t)m+1ull)) / 2;
        if(sum > target)
        {
            minSteps = m;
            r = m-1;
        }
        else if(sum < target)
            l = m+1;
        else
            return m;
    }

    return minSteps;
}