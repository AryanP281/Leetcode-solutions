
#include<bits/stdc++.h>

using namespace std;

int trap(vector<int>& height);

int main()
{
    vector<int> height = {4,2,0,3,2,5};
    cout << trap(height);

    getchar();
    return 0;
}

int trap(vector<int>& height)
{
    int trappedWater = 0;

    int l = height[0] > *height.rbegin() ? 0 : 1;
    int r = l ? height.size()-1 : height.size()-2;
    int maxLeft = l ? height[0] : 0;
    int maxRight = l ? 0 : *height.rbegin();
    bool checkLeft = l;

    while(l < r)
    {
        if(checkLeft)
            trappedWater += max(0, maxLeft - height[l]);
        else
            trappedWater += max(0, maxRight - height[r]);

        if(height[l] < height[r])
        {
            maxLeft = max(maxLeft, height[l]);
            l++;
            checkLeft = true;
        }
        else
        {
            maxRight = max(maxRight, height[r]);
            r--;
            checkLeft = false;
        }
    }    

    return trappedWater;
}