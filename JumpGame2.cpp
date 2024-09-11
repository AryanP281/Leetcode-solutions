
#include<bits/stdc++.h>

using namespace std;

int jump(vector<int>& nums);

int main()
{
    vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
    cout << jump(nums);

    getchar();
    return 0;
}

int jump(vector<int>& nums) 
{
    int* minJumps = new int[nums.size()]();

    for(int i = nums.size()-2; i >= 0; --i)
    {   
        minJumps[i] = INT_MAX;
        for(int j = i+1; j <= i+nums[i] && j < nums.size(); j++)
        {
            if(minJumps[j] == INT_MAX)
                continue;
            
            minJumps[i] = min(minJumps[i], 1 + minJumps[j]);
        }
    }

    int result = minJumps[0];

    delete[] minJumps;

    return result;        
}