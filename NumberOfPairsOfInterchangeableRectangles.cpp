
#include<bits/stdc++.h>

using namespace std;

long long interchangeableRectangles(vector<vector<int>>& rectangles);

int main()
{

    vector<vector<int>> rects = {{4,5},{7,8}};
    cout << interchangeableRectangles(rects);

    getchar();
    return 0;
}

long long interchangeableRectangles(vector<vector<int>>& rectangles) 
{
    unordered_map<double,int> ratios;
    unordered_map<double,int>::iterator itr;
    for(int i = 0; i < rectangles.size(); ++i)
    {
        double ratio = (double)rectangles[i][0] / (double)rectangles[i][1];
        itr = ratios.find(ratio);
        if(itr == ratios.end())
            ratios[ratio] = 1;
        else
            itr->second++;
    }

    long long rectCount = 0;
    for(itr = ratios.begin(); itr != ratios.end(); ++itr)
    {
        rectCount += ((long long)itr->second * (long long)(itr->second-1)) / 2;
    }

    return rectCount;
}