
#include<bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums);

int main()
{

    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums);

    getchar();
    return 0;
}

bool canJump(vector<int>& nums) 
{
    int lastValidPos = nums.size()-1;
    bool currPosValid = true;

    for(int i = nums.size()-2; i >= 0; --i)
    {
        if(lastValidPos - i <= nums[i])
        {
            lastValidPos = i;
            currPosValid = true;
        }
        else
            currPosValid = false;
    }

    return currPosValid;        
}