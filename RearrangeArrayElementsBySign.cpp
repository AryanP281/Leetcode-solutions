
#include<bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums);

int main()
{
    vector<int> nums = {3,1,-2,-5,2,-4};
    rearrangeArray(nums);

    getchar();
    return 0;
}

vector<int> rearrangeArray(vector<int>& nums) 
{
    queue<int> positivePos;
    queue<int> negativePos;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > 0)
            positivePos.push(i);
        else
            negativePos.push(i);
    }
    
    vector<int> rearrangedArray;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(i % 2)
        {
            rearrangedArray.push_back(nums[negativePos.front()]);
            negativePos.pop();
        }
        else
        {
            rearrangedArray.push_back(nums[positivePos.front()]);
            positivePos.pop();
        }
    }

    return rearrangedArray;
}

