
#include<bits/stdc++.h>

using namespace std;

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2);

int main()
{

    vector<int> arr1 = {1,2,3};
    vector<int> arr2 = {4,4,4};

    cout << longestCommonPrefix(arr1, arr2);

    getchar();

    return 0;
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
{
    unordered_set<int> arr1Prefixes;
    
    for(int i = 0; i < arr1.size(); ++i)
    {
        int currPrefix = arr1[i];
        do
        {
            arr1Prefixes.insert(currPrefix);
            currPrefix = floor((double)currPrefix / 10.0);
            if(arr1Prefixes.count(currPrefix))
                break;
        } while(currPrefix > 0);
    }

    int longestPrefix = 0;
    for(int i = 0; i < arr2.size(); ++i)
    {
        int currPrefix = arr2[i];
        do
        {
            if(arr1Prefixes.count(currPrefix))
            {
                longestPrefix = max(longestPrefix, (int)floor(log10(currPrefix) + 1.0));
                break;
            }

            currPrefix = floor((double)currPrefix / 10.0);
        } while(currPrefix > 0);
    }

    return longestPrefix;
}