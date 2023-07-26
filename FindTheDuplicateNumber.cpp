
#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums);

int main()
{
    vector<int> nums = {2,5,9,6,9,3,8,9,7,1};
    cout << findDuplicate(nums);

    getchar();
    return 0;
}

int findDuplicate(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());

    int duplicate;
    for(int a = 1; a < nums.size(); ++a)
    {
        if(nums[a] == nums[a-1])
        {
            duplicate = nums[a];
            break;
        }
    }

    return duplicate;
}