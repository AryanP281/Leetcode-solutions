
#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main()
{
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    cout << removeDuplicates(nums);

    getchar();
    return 0;
}

int removeDuplicates(vector<int>& nums) 
{
    int offset = 0;
    int k = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(i-2-offset >= 0 && nums[i] == nums[i-2-offset])
            offset++;
        else
        {
            nums[i-offset] = nums[i];
            k++;
        }
    }   

    return k;
}