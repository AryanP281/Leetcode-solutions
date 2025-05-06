
#include<bits/stdc++.h>

using namespace std;

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums);
void countSort(int digit, vector<int>& mapping, vector<int>& arr);

int main()
{
    vector<int> mapping = {0,1,2,3,4,5,6,7,8,9};
    vector<int> nums = {789,456,123};

    sortJumbled(mapping, nums);

    getchar();

    return 0;
}

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
{
    const int MAX_NUM = *max_element(nums.begin(), nums.end());
    if(MAX_NUM == 0)
        return nums;
    const int MAX_DIGITS = floor(log10(MAX_NUM));
    
    vector<int> result = nums;
    for(int digit = 0; digit <= MAX_DIGITS; ++digit)
    {
        countSort(digit, mapping, result);
    }

    return result;
}

void countSort(int digit, vector<int>& mapping, vector<int>& arr)
{
    int counts[10] = {0};

    const int exp = pow(10,digit);
    for(int i = 0; i < arr.size(); ++i)
    {
        if(arr[i] < exp && exp != 1)
            counts[0]++;
        else
            counts[mapping[(arr[i] / exp) % 10]]++;
    }

    int prefixSums[10] = {0};
    prefixSums[0] = counts[0];
    for(int i = 1; i < 10; ++i)
    {
        prefixSums[i] = prefixSums[i-1] + counts[i];
    }

    vector<int> output(arr.size(), 0);
    for(int i = arr.size()-1; i >= 0; --i)
    {
        int pos = (arr[i] < exp && exp != 1) ? 0 : mapping[(arr[i] / exp) % 10];
        
        output[prefixSums[pos]-1] = arr[i];
        prefixSums[pos]--;
    }

    arr = output;
}