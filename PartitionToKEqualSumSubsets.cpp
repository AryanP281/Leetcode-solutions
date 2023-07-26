#include<bits/stdc++.h>

using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k);
bool canFormSum(int i, int currSubsetSum, int targetSum, int k, int16_t* elementMask, vector<int>& arr);

int main()
{
    vector<int> nums = {1,1,1,1,2,2,2,2};

    cout << (canPartitionKSubsets(nums,4) ? "True" : "False");

    getchar();
    return 0;
}

bool canPartitionKSubsets(vector<int>& nums, int k) 
{
    int arrSum = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        arrSum += nums[i];
    }

    if(k == 0 || arrSum % k != 0)
        return false;
    
    int16_t elementsMask = 0;
    int targetSum = arrSum / k;
    
    return canFormSum(0, 0, targetSum, k, &elementsMask, nums);
}

bool canFormSum(int i, int currSubsetSum, int targetSum, int k, int16_t* elementMask, vector<int>& arr)
{
    if(k == 0)
        return true;
    else if(currSubsetSum == targetSum)
        return canFormSum(0, 0, targetSum, k-1,elementMask, arr);
    else if(i >= arr.size() || currSubsetSum > targetSum)
        return false;

    if(((*elementMask) & (1 << i)) == 0)
    {
        *elementMask |= (1 << i);
        if(canFormSum(i+1,currSubsetSum+arr[i],targetSum,k,elementMask,arr))
            return true;
        
        *elementMask &= ~(1 << i);
    }

    return canFormSum(i+1,currSubsetSum,targetSum,k,elementMask,arr);
}

/*
if(currSubsetSum == targetSum || k == 0)
        return true;
    else if(i >= arr.size() || currSubsetSum > targetSum)
        return false;

    if(((*elementMask) & (1 << i)) == 0)
    {
        *elementMask |= (1 << i);
        if(canFormSum(i+1,currSubsetSum+arr[i],targetSum,elementMask,arr))
            return true;
        
        *elementMask &= ~(1 << i);
    }

    return canFormSum(i+1,currSubsetSum,targetSum,elementMask,arr);
*/

