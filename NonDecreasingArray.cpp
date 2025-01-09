
#include<bits/stdc++.h>

using namespace std;

bool checkPossibility(vector<int>& nums);

int main()
{
    vector<int> nums = {4,2,1};
    cout << checkPossibility(nums);

    getchar();
    return 0;
}

bool checkPossibility(vector<int>& nums) 
{
    int violationCount = 0;
    for(int i = 0; i < nums.size()-1; ++i)
    {
        if(nums[i] > nums[i+1])
        {
            if(violationCount > 0)
                return false;
            else
            {
                if(i == 0 || (i < nums.size()-2 && nums[i-1] <= nums[i+1]) || i == nums.size()-2 || (i > 0 && nums[i] <= nums[i+2]))
                    violationCount++;
                else
                    return false;
            }
        }
    }

    return true;
}