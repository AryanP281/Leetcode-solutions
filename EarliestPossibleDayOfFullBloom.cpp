
/*
At any point i, consider plants P1 and P2 with (plant time, growtime) = (p1,g1) & (p2,g2)
Time required if P1 is planted before P2 = T1 = p1 + max(g1, p2+g2)
Time required if P2 is planted before P1 = T2 = p2 + max(g2, p1+g1)
If T1 > T2, planting order should be P1->P2. Else order should be P2->P1
Thus, the plants can be sorted using this observation to determine the correct order for minimum bloom time.
*/

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime);

int main()
{
    vector<int> plantTime = {1,2,3,2};
    vector<int> growTime = {2,1,2,1};

    cout << earliestFullBloom(plantTime, growTime);

    getchar();
    return 0;
}

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
{
    vector<Vec> plants(plantTime.size(), Vec(0,0));
    for(int i = 0; i < plants.size(); ++i)
    {
        plants[i].first = plantTime[i];
        plants[i].second = growTime[i];
    }

    sort(plants.begin(), plants.end(), [](Vec& p1, Vec& p2) -> bool {
        return (p1.first + max(p1.second, p2.first + p2.second)) < (p2.first + max(p2.second, p1.first+p1.second));
    });

    int maxTime = 0;
    int currTime = 0;
    for(int i = 0; i < plants.size(); ++i)
    {
        maxTime = max(maxTime, currTime + plants[i].first + plants[i].second);
        currTime += plants[i].first;
    }

    return maxTime;
}