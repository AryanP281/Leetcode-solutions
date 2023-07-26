
#include<bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T);

int main()
{
    vector<int> arr = {89,62,70,58,47,47,46,76,100,70};
    dailyTemperatures(arr);

    getchar();
    return 0;
}

vector<int> dailyTemperatures(vector<int>& T) 
{
    stack<int> nextMaxes;
    
    vector<int> res(T.size(), 0);
    nextMaxes.push(T.size()-1);
    for(int a = T.size()-2; a >= 0; --a)
    {
        while(!nextMaxes.empty() && T[nextMaxes.top()] <= T[a])
        {
            nextMaxes.pop();
        }

        if(nextMaxes.empty())
            res[a] = 0;
        else
            res[a] = nextMaxes.top() - a;

        nextMaxes.push(a);
    }

    return res;
}