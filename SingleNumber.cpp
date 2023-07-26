
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

int singleNumber(vector<int>& nums) 
{
    int xored = nums[0];
    for(int a = 1; a < nums.size(); ++a)
    {
        xored ^= nums[a];
    }

    return xored;   
}