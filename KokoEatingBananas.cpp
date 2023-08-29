
#include<bits/stdc++.h>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h);

int main()
{
    vector<int> piles = {30,11,23,4,20};
    cout << minEatingSpeed(piles, 6);

    getchar();
    return 0;
}

int minEatingSpeed(vector<int>& piles, int h) 
{
    auto getMax = [&piles]() -> int {
        int maxVal = piles[0];
        for(int i = 1; i < piles.size(); ++i)
        {
            maxVal = max(maxVal, piles[i]);
        }

        return maxVal;
    };

    int l = 1;
    int r = getMax();

    int minSpeed = r;
    while(l <= r)
    {
        int m = floor((l+r) / 2);

        int currTime = 0;
        for(int i = 0; i < piles.size() && currTime <= h; ++i)
        {
            currTime += ceil((float)piles[i] / (float)m);
        }

        if(currTime > h)
            l = m+1;
        else
        {
            minSpeed = m;
            r = m-1;
        }
    }

    return minSpeed;
}