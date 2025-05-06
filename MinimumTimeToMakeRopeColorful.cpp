
#include<bits/stdc++.h>

using namespace std;

int minCost(string colors, vector<int>& neededTime);

int main()
{
    vector<int> arr = {1,2,3,4,1};
    cout << minCost("aabaa", arr);

    getchar();
    return 0;
}

int minCost(string colors, vector<int>& neededTime) 
{
    int* prefixSum = new int[neededTime.size()]();
    prefixSum[0] = neededTime[0];

    for(int i = 1; i < neededTime.size(); ++i)
    {
        prefixSum[i] = prefixSum[i-1] + neededTime[i];
    }

    colors += "-"; //Sentinel character
    int l = 0;
    int totalCost = 0;
    for(int r = 1; r < colors.size(); ++r)
    {
        if(colors[r] != colors[l])
        {
            if(r > l+1)
            {
                int bestCost = INT_MAX;
                for(int k = l; k < r; k++)
                {
                    bestCost = min(bestCost, (prefixSum[k] - prefixSum[l] + neededTime[l] - neededTime[k]) + (prefixSum[r-1] - prefixSum[k]));
                }
                totalCost += bestCost;
            }
            l = r;
        }
    }

    delete[] prefixSum;

    return totalCost;
}