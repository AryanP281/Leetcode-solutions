
#include<bits/stdc++.h>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points);

int main()
{
    vector<vector<int>> points = {{1,2},{1,4},{3,5},{2,5},{6,7},{7,8},{6,9}};
    cout << findMinArrowShots(points);

    getchar();
    return 0;
}

int findMinArrowShots(vector<vector<int>>& points) 
{
    sort(points.begin(), points.end(), [](vector<int>& i1, vector<int>& i2) -> bool {
        return (i1[0] < i2[0]) || (i1[0] == i2[0] && i1[1] <= i2[1]);
    });

    int l = 0;
    int r = 1;
    int shotsCount = 0;
    while(r < points.size())
    {
        if(points[r][0] > points[l][1])
        {
            ++shotsCount;
            l = r;
        }
        else
        {
            if(points[r][1] < points[l][1])
                l = r;
        }

        ++r;
    }

    return ++shotsCount;
}