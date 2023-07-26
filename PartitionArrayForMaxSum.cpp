
#include<bits/stdc++.h>

using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k);
int getMaxSum(vector<int>& arr, int l, int k, int* lookupTable);

int main()
{
    vector<int> arr = {1};
    cout << maxSumAfterPartitioning(arr, 1);

    getchar();
    return 0;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) 
{
    int* lookupTable = new int[arr.size()];
    fill_n(lookupTable, arr.size(), -1);
    lookupTable[arr.size()-1] = *arr.rbegin();

    int maxSum = getMaxSum(arr,0,k,lookupTable);
    delete[] lookupTable;

    return maxSum;
}

int getMaxSum(vector<int>& arr, int l, int k, int* lookupTable)
{
    if(l >= arr.size())
        return 0;
    else if(lookupTable[l] != -1)
        return lookupTable[l];
    
    int currPartitionMax = arr[l];
    int newSum = 0;
    for(int a = 0; a < k && (l+a) < arr.size(); ++a)
    {
        currPartitionMax = max(currPartitionMax, arr[l+a]);
        newSum = currPartitionMax*(a+1) + getMaxSum(arr,l+a+1,k,lookupTable);
        lookupTable[l] = max(lookupTable[l], newSum);
    }

    return lookupTable[l];
}