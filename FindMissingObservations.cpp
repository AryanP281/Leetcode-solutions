
#include<bits/stdc++.h>

using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n);

int main()
{
    vector<int> rolls = {4,5,6,2,3,6,5,4,6,4,5,1,6,3,1,4,5,5,3,2,3,5,3,2,1,5,4,3,5,1,5};
    int mean = 4;
    int n = 40;

    vector<int> missingVals = missingRolls(rolls, mean, n);
    for(int i : missingVals)
    {
        cout << i << ", ";
    }

    getchar();
    return 0;
}

vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
{

    int target = (mean*(n+rolls.size())) - accumulate<vector<int>::iterator, int>(rolls.begin(), rolls.end(), 0);

    if(target > 6*n || target < n)
        return vector<int>();

    vector<int> missingVals(n, floor(target / n));
    int currSum = n*((int)floor(target / n));

    int i = 0;
    int oldVal;
    while(currSum < target)
    {
        oldVal = missingVals[i];
        missingVals[i] = min(6, missingVals[i]+(target - currSum));
        currSum += min(6 - oldVal, target-currSum);
        i++;
    }

    return missingVals;
}