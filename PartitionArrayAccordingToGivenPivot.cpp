
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();

    return 0;
}

vector<int> pivotArray(vector<int>& nums, int pivot) 
{
    vector<int> pivotedArr(nums.size(), pivot);

    //Filling smaller elements
    int ptr = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] < pivot)
            pivotedArr[ptr++] = nums[i];
    }
    
    //Filling larger elements
    ptr = nums.size()-1;
    for(int i = nums.size()-1; i >= 0; --i)
    {
        if(nums[i] > pivot)
            pivotedArr[ptr--] = nums[i];
    }

    return pivotedArr;
}