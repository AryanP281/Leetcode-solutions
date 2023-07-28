
//Calculating finish time may introduce floating point numbers, a simple trick to avoid this is to change a/b < c/d to a*d < c*b.

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int carFleet(int target, vector<int>& position, vector<int>& speed);

int main()
{
    vector<int> positions = {0,2,4};
    vector<int> speeds = {4,2,1};
    cout << carFleet(100,positions,speeds);

    getchar();
    return 0;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) 
{
    vector<Vec> cars;
    for(int i = 0; i < position.size(); ++i)
    {
        cars.push_back(Vec(position[i], speed[i]));
    }

    sort(cars.begin(), cars.end(), [](const Vec& c1, const Vec& c2) -> bool {
        return c1.first < c2.first;
    });

    stack<float> fleetTimes;
    fleetTimes.push((float)(target - cars[0].first) / (float)cars[0].second);
    float currTime;
    for(int i = 1; i < cars.size(); ++i)
    {
        currTime = (float)(target - cars[i].first) / (float)cars[i].second;
        while(fleetTimes.size() && currTime >= fleetTimes.top())
        {
            fleetTimes.pop();
        }
        fleetTimes.push(currTime);
    }

    return fleetTimes.size();
}