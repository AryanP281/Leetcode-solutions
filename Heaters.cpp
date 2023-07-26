
#include<bits/stdc++.h>

using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters);
bool validRadius(vector<int>& houses, vector<int>& heaters, int radius);

int main()
{
    vector<int> houses = {1};
    vector<int> heaters = {1,2,3,4};
    cout << findRadius(houses, heaters);

    getchar();
    return 0;
}

int findRadius(vector<int>& houses, vector<int>& heaters) 
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    
    int l = 0;
    int r = max(*heaters.rbegin()-houses[0], *houses.rbegin() - *heaters.rbegin());
    int minRadius = r+1;

    int mid;
    while(l <= r)
    {
        mid = floor((l+r)/2);
        if(validRadius(houses, heaters, mid))
        {
            minRadius = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }   

    return minRadius;
}

bool validRadius(vector<int>& houses, vector<int>& heaters, int radius)
{
    int i = 0;
    int j = 0;

    while(i < houses.size() && j < heaters.size())
    {
        if(houses[i] < heaters[j]-radius)
            return false;
        
        while(i < houses.size() && houses[i] <= heaters[j]+radius)
            i++;
        j++;
    }

    return (i == houses.size());
}
