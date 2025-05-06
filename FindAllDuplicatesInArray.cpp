
#include<bits/stdc++.h>

using namespace std;

vector<int> findDuplicates(vector<int>& nums);

int main()
{
    vector<int> nums = {1};
    findDuplicates(nums);

    getchar();
    return 0;
}

vector<int> findDuplicates(vector<int>& nums) 
{
    vector<int> duplicates;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == i+1)
            continue;
        int prevVal = -1;
        int currPos = i;
        do
        {
            int curr = nums[currPos];
            nums[currPos] = prevVal;
            if(nums[curr-1] == curr)
            {
                duplicates.push_back(curr);
                break;
            }
            prevVal = curr;
            currPos = curr-1;
        } while (prevVal != -1);
    }

    return duplicates;
}