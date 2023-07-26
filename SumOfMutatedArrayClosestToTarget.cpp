
#include<bits/stdc++.h>

using namespace std;

int findBestValue(vector<int>& arr, int target);
int getPos(vector<int>& sorted, int x);

int main()
{
    vector<int> arr = {60864,25176,27249,21296,20204};
    cout << findBestValue(arr, 56803);

    getchar();
    return 0;
}

int findBestValue(vector<int>& arr, int target) 
{
    sort(arr.begin(), arr.end());
    vector<int> cumSum(arr.size(),0);
    *(cumSum.rbegin()) = *(arr.rbegin());
    for(int i = arr.size()-2; i >= 0; --i)
    {
        cumSum[i] = cumSum[i+1] + arr[i];
    }

    int bestVal = -1;
    int minDiff = INT_MAX;
    int limit = min(target, *cumSum.rbegin());
    for(int i = 0; i <= limit; ++i)
    {
        int pos = getPos(arr, i);
        int newSum = cumSum[0] - cumSum[pos] + i*(arr.size()-pos);
        if(abs(newSum - target) < minDiff)
        {
            minDiff = abs(newSum - target);
            bestVal = i;
        }
    }

    return bestVal;
}

int getPos(vector<int>& sorted, int x)
{
    int l = 0;
    int r = sorted.size()-1;

    int mid;
    int res = r;
    while(l <= r)
    {
        mid = (l+r) / 2;
        if(sorted[mid] >= x)
        {
            res = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }

    return res;
}