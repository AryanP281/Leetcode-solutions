
#include<bits/stdc++.h>

using namespace std;

int maxDistance(vector<int>& position, int m) ;
int distanceIsPossible(int dist, vector<int>& position, int m);

int main()
{
    int d;
    for(int i = 0; i < 10000; ++i)
    {
        vector<int> pos = {1,2,3,4,7};
        d = maxDistance(pos, 3);

        if(d != 3)
        {
            cout << d;
            break;
        }    
    }
    cout << "Complete";

    getchar();
    return 0;
}

int maxDistance(vector<int>& position, int m) 
{
    sort(position.begin(), position.end());

    int maxForce = 1;
    int l = 1;
    int r = *position.rbegin() - position[0];
    int mid, ballsLeft, p, curr;
    while(l <= r)
    {
        mid = (r+l)/2;

        int currForce = distanceIsPossible(mid, position, m);
        if(currForce == -1)
            r = mid-1;
        else
        {
            maxForce = max(maxForce, currForce);
            l = currForce+1;
        }
    }

    return maxForce;
}

int distanceIsPossible(int dist, vector<int>& position, int m)
{
    int minDist = position[position.size()-1] - position[0];

    --m;
    int prevPos = 0;
    for(int i = 1; i < position.size() && m > 0; ++i)
    {
        if(position[i] - position[prevPos] >= dist)
        {
            minDist = min(minDist, position[i] - position[prevPos]);
            prevPos = i;
            --m;
        }
    }

    return (minDist*(m == 0)) + (-1*(m != 0));
}

