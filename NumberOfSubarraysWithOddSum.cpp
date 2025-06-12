
#include<bits/stdc++.h>

using namespace std;

int numOfSubarrays(vector<int>& arr);

int main()
{

    getchar();

    return 0;
}

int numOfSubarrays(vector<int>& arr) 
{
    const int MOD = 1e9 + 7;
    
    uint64_t sumTypes[] = {1,0};
    
    int currSum = 0;
    int subArrayCount = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        currSum += arr[i];
        subArrayCount = (currSum % 2) ? ((subArrayCount % MOD) + (sumTypes[0] % MOD)) % MOD : ((subArrayCount % MOD) + (sumTypes[1] % MOD)) % MOD;
        sumTypes[currSum % 2]++;
    }

    return subArrayCount;
}