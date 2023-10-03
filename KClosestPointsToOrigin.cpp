
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,double> Vec;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k);
int getPivotIndex(int l, int r);
void swap(vector<Vec>& arr, int i, int j);
int partitionArr(vector<Vec>& arr, int l, int r);

int main()
{
    vector<vector<int>> pts = {{9997,9997},{9996,9998}};
    kClosest(pts, 1);

    getchar();
    return 0;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
{
    vector<Vec> distances;
    for(int i = 0; i < points.size(); ++i)
    {
        distances.push_back(Vec(i, sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]))));
    }

    int l = 0;
    int r = points.size()-1;
    int kthPos = -1;
    while(l <= r && kthPos < 0)
    {
        int pivot = getPivotIndex(l,r);
        swap(distances, pivot, l);
        int pivotIndex = partitionArr(distances, l, r);

        if(pivotIndex == k-1)
            kthPos = pivotIndex;
        else if(pivotIndex > k-1)
            r = pivotIndex-1;
        else
            l = pivotIndex+1;
    }

    vector<vector<int>> res;
    for(int i = 0; i <= kthPos; ++i)
    {
        res.push_back(points[distances[i].first]);
    }

    return res;
}

int getPivotIndex(int l, int r)
{
    return (rand() % (r-l+1)) + l;
}

void swap(vector<Vec>& arr, int i, int j)
{
    Vec temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partitionArr(vector<Vec>& arr, int l, int r)
{
    int i = l+1;
    for(int j = i; j <= r; ++j)
    {
        if(arr[j].second <= arr[l].second)
        {
            swap(arr, j, i);
            i++;
        }
    }

    swap(arr, l, i-1);

    return i-1;
}