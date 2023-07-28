
#include<bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures);

int main()
{

    vector<int> temps = {30,60,90};
    vector<int> warmerTemps = dailyTemperatures(temps);

    for(auto t : warmerTemps)
    {
        cout << t << ", ";
    }

    getchar();
    return 0;
}

vector<int> dailyTemperatures(vector<int>& temperatures) 
{
    vector<int> warmerTemps(temperatures.size(), 0);

    stack<int> toProcess;
    toProcess.push(0);

    for(int i = 1; i < temperatures.size(); ++i)
    {
        while(!toProcess.empty() && temperatures[i] > temperatures[toProcess.top()])
        {
            warmerTemps[toProcess.top()] = i - toProcess.top();
            toProcess.pop();
        }

        toProcess.push(i);
    }

    return warmerTemps;   
}