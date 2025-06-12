
#include<bits/stdc++.h>

using namespace std;

int main()
{


    getchar();

    return 0;
}

long long countBadPairs(vector<int>& nums) 
{
    typedef long long ll;
    
    unordered_map<int,int> seen;

    ll badPairs = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        unordered_map<int,int>::iterator itr = seen.find(nums[i] - i);
        ll goodPairs = itr == seen.end() ? 0 : itr->second;
        badPairs += i - goodPairs;

        seen[nums[i]-i]++;
    }

    return badPairs;
}