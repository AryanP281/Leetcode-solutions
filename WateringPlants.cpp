
#include<bits/stdc++.h>

using namespace std;

int wateringPlants(vector<int>& plants, int capacity);

int main()
{
    vector<int> plants = {7,7,7,7,7,7,7};

    cout << wateringPlants(plants, 8);

    getchar();
    return 0;
}

int wateringPlants(vector<int>& plants, int capacity) 
{
    int currLevel = capacity;
    int steps = 0;

    for(int i = 0; i < plants.size(); ++i)
    {
        steps++;
        if(plants[i] > currLevel)
        {
            steps += 2*((i-1) + 1);
            currLevel = capacity;
        }

        currLevel -= plants[i];
    }

    return steps;
}
