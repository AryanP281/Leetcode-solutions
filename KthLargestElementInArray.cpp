#include<bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int>& nums, int k);
int* partition(vector<int>& arr, int l, int r, int p);
void swap(vector<int>& arr, int i, int j);

int main()
{

    vector<int> nums = {2,1};
    cout << findKthLargest(nums, 2);

    getchar();
    return 0;
}

int findKthLargest(vector<int>& nums, int k) 
{
    srand(time(NULL));
    
    int l = 0;
    int r = nums.size()-1;

    while(l <= r)
    {
        int* pr= partition(nums, l, r, l + (rand() % (r-l+1)));
        if((pr[0] + 1) <= k && (pr[1]+1) >= k)
            return nums[pr[0]];
        else if((pr[0] + 1) > k)
            r = pr[0]-1;
        else
            l = pr[1] + 1;
    }

    return 0;
}

int* partition(vector<int>& arr, int l, int r, int p)
{
    swap(arr, l, p);

    int i = l;
    for(int j = i+1; j <= r; ++j)
    {
        if(arr[j] > arr[i])
        {
            swap(arr, i+1,j);
            swap(arr,i,i+1);
            i++;
        }
    }

    swap(arr,i,r);
    i = r;
    for(int j = i-1; j >= l; --j)
    {
        if(arr[j] < arr[i])
        {
            swap(arr, i-1,j);
            swap(arr,i,i-1);
            i--;
        }
    }

    int* pivotRange = new int[2];
    pivotRange[0] = i;
    pivotRange[1] = i;
    while(pivotRange[0] >= 0 && arr[pivotRange[0]] == arr[pivotRange[1]])
        pivotRange[0]--;
    pivotRange[0]++;

    return pivotRange;
}

void swap(vector<int>& arr, int i, int j)
{
    if(i == j)
        return;
    
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}