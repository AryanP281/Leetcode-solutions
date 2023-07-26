
#include<bits/stdc++.h>

using namespace std;

int getMaxLen(vector<int>& nums);

int main()
{
    vector<int> nums = {-1,-2,-3,0,1};
    cout << getMaxLen(nums);

    getchar();
    return 0;
}

int getMaxLen(vector<int>& nums) 
{
    int maxLen = 0;
    int negs = 0;
    int firstNeg = -1;
    int l = -1;
    for(int r = 0; r < nums.size(); ++r)
    {
        if(nums[r] == 0)
        {
            firstNeg = -1;
            negs = 0;
            l = r;
            continue;
        }
        
        if(nums[r] < 0)
        {
            negs++;
            if(firstNeg == -1)
                firstNeg = r;
        }
        
        if(negs % 2 == 0)
            maxLen = max(maxLen, r-l);
        else
            maxLen = max(maxLen, r-firstNeg);

    }

    return maxLen;   
}