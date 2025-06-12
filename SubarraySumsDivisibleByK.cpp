/*
MATHEMATICAL PROOF - 
(S1 + S2) % k = S1 % k
((S1 % k) + (S2 % k)) % k = (S1 % k)

But, (S1 % k) = (S1 % k) % k

Thus, (S1 % k) + (S2 % k) = (S1 % k) i.e (S2 % K) = 0 i.e S2 is divisible by k
*/



#include<bits/stdc++.h>

using namespace std;

int main()
{


    getchar();

    return 0;
}

int subarraysDivByK(vector<int>& nums, int k) 
{
    unordered_map<int,int> seenMods;
    seenMods[0] = 1;
    
    int currSum = 0;
    unordered_map<int,int>::iterator itr;
    int subarrayCount = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        currSum += nums[i];
        int currMod = currSum >= 0 ? currSum % k : ((currSum % k) + k) % k;
        itr = seenMods.find(currMod);
        if(itr != seenMods.end())
            subarrayCount += itr->second;
        seenMods[currMod]++;
    }

    return subarrayCount;
}