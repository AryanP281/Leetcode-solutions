
#include<bits/stdc++.h>

using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold);

int main()
{
    vector<int> arr = {4,4,4,4};
    cout << numOfSubarrays(arr, 4, 1);

    getchar();
    return 0;
}

int numOfSubarrays(vector<int>& arr, int k, int threshold) 
{
    int windowStart = 0;
    int windowEnd = min((int)arr.size(),k);
    double avg = 0.0;
    for(int a = 0; a < windowEnd; ++a)
    {
        avg += arr[a];
    }
    avg /= k;

    int subarrayCount = 1*(avg >= threshold);
    for(; windowEnd < arr.size(); ++windowEnd,++windowStart)
    {
        avg = ((avg*k) - arr[windowStart] + arr[windowEnd]) / k;
        subarrayCount += 1*(avg >= threshold);
    }

    return subarrayCount;
}