
#include<bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums);

int main()
{
    vector<int> nums = {6,2,0,9,7};
    rearrangeArray(nums);

    getchar();
    return 0;
}

vector<int> rearrangeArray(vector<int>& nums) 
{
    /*Based on observation : A number can be the average of its neighbors if one neighbor is smaller than the number and the other is greater than the number.*/
    
    sort(nums.begin(), nums.end());

    vector<int> rearranged = {nums[0]};
    int indices[2] = {1,(int)nums.size()-1};
    for(int i = 1; i < nums.size(); ++i)
    {
        if(i % 2 != 0)
            rearranged.push_back(nums[indices[1]--]);
        else
            rearranged.push_back(nums[indices[0]++]);
    }

    return rearranged;
}