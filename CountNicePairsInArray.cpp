
#include<bits/stdc++.h>

using namespace std;

int countNicePairs(vector<int>& nums);
int getReverse(int num);

const int MOD = 1e9 + 7;

int main()
{
    vector<int> nums = {13,10,35,24,76};
    cout << countNicePairs(nums);

    getchar();
    return 0;
}

int countNicePairs(vector<int>& nums) 
{
    int rev, sub;
    unordered_map<int,int> subtractions;
    int nicePairs = 0;
    for(int i = nums.size()-1; i >= 0; --i)
    {
        rev = getReverse(nums[i]);
        sub = nums[i] - rev;

        if(subtractions.count(sub))
            nicePairs = (nicePairs + subtractions[sub]) % MOD;
        subtractions[sub]++;
    }

    return nicePairs;
}

int getReverse(int num)
{
    if(num == 0)
        return 0;
    
    int rev = 0;
    int currPow = floor(log10(num));
    while(num > 0)
    {
        rev += pow(10,currPow) * (num % 10);
        num /= 10;
        currPow--;
    }

    return rev;
}