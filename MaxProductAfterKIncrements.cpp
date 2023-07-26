/*
Consider array of size 2 with elements a,b st a > b
(a+1)*b = ab + b
a*(b+1) = ab + a
ab + a > ab + b as a > b

Consider array of size 3 with elements a,b,c st a > b > c
(a+1)*bc = abc + bc
a*(b+1)c = abc + ac
ab(c+1) = abc + ab
abc + ac > abc + bc as a > b
abc + ab > abc + ac as b > c
abc + ab > abc + bc due to transitive property

The above trend holds for larger arrays as well
*/  

#include<bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int maximumProduct(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {24,5,64,53,26,38};
    cout << maximumProduct(nums, 54);

    getchar();
    return 0;
}

int maximumProduct(vector<int>& nums, int k) 
{
    map<int64_t,int64_t> valsCount;

    for(int i = 0; i < nums.size();++i)
    {
        valsCount[nums[i]]++;
    }

    for(int i = 0; i < k; ++i)
    {
        valsCount[valsCount.begin()->first + 1]++;
        if(valsCount.begin()->second == 1)
            valsCount.erase(valsCount.begin());
        else
            valsCount.begin()->second--;
    }

    int64_t prod = 1;
    for(map<int64_t,int64_t>::iterator itr = valsCount.begin(); itr != valsCount.end(); ++itr)
    {
        for(int j = 0; j < itr->second; ++j)
        {
            prod = (prod * itr->first) % MOD;
        }
    }

    return prod;
}