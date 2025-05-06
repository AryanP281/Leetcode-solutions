
#include<bits/stdc++.h>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x);
int findStart(vector<int>& arr, int x);

int main()
{
    vector<int> arr = {1,1,2,3,4,5};
    findClosestElements(arr,4,6);

    getchar();
    return 0;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    int l = findStart(arr, x);
    int r = l+1;
    while(r - l - 1 < k)
    {
        if(r >= arr.size() && l >= 0)
            l--;
        else if(l < 0 && r < arr.size())
            r++;
        else if(abs(arr[l] - x) <= abs(arr[r] - x))
            l--;
        else
            r++;
    }

    vector<int> closestElements;
    for(int i = l+1; i < r; ++i)
    {
        closestElements.push_back(arr[i]);
    }

    return closestElements;
}

int findStart(vector<int>& arr, int x)
{
    int l = 0;
    int r = arr.size()-1;
    int start = -1;

    while(l <= r)
    {
        int m = (l+r) / 2;
        if(arr[m] > x)
            r = m-1;
        else if(arr[m] == x)
        {
            start = m;
            break;
        }
        else
        {
            start = m;
            l = m+1;
        }

    }

    return start;
}