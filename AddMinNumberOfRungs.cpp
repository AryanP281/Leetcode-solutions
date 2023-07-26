
#include<bits/stdc++.h>

using namespace std;

int addRungs(vector<int>& rungs, int dist);

int main()
{
    vector<int> rungs = {3,4,6,7};
    cout << addRungs(rungs, 2);

    getchar();
    return 0;
}

int addRungs(vector<int>& rungs, int dist) 
{
    int rungsReq = 0;
    int prevRung = 0;
    for(int i = 0; i < rungs.size(); prevRung = rungs[i], ++i)
    {
        if(rungs[i] - prevRung > dist)
        {
            int height = rungs[i] - prevRung;
            rungsReq += floor(height / dist) - 1*(height % dist == 0);
        }
    }

    return rungsReq;
}