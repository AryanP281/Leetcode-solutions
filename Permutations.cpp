#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> permute(vector<int>& nums);
void generatePermutations(int i, vector<int>& currP, int pMask, vector<int>& nums, vector<vector<int>>& perms);

int main()
{
    vector<int> nums = {5,4,6,2};
    permute(nums);

    getchar();
    return 0;
}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> permutations;
    
    int pMask = pow(2,nums.size())-1;
    vector<int> currPermutation;
    generatePermutations(0, currPermutation, pMask, nums, permutations);

    return permutations;
}

void generatePermutations(int i, vector<int>& currP, int pMask, vector<int>& nums, vector<vector<int>>& perms)
{
    if(i >= nums.size())
    {
        perms.push_back(currP);
        return;
    }

    for(int j = 0; j < 32; ++j)
    {
        if((pMask >> j) & 1)
        {
            currP.push_back(nums[j]);
            int newMask = (pMask & ~(1<<j));
            generatePermutations(i+1,currP,newMask,nums,perms);
            currP.pop_back();
        }
    }

}