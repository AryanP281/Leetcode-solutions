
#include<bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int>& nums);

int main()
{
    vector<int> nums = {3,3,7,7,10,11,11};
    cout << singleNonDuplicate(nums);

    getchar();
    return 0;
}

int singleNonDuplicate(vector<int>& nums) 
{
    if(nums.size() == 1) return nums[0];
    
    int l = 0;
    int r = nums.size()-1;
    int duplicate;
    while(l < r)
    {
        int mid = l + ((r-l) / 2);
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
        {
            duplicate = nums[mid];
            break;
        }
        else if(nums[mid] == nums[mid-1])
        {
            if((mid-2) >= l && ((mid-2)-l+1) % 2 != 0) r = mid-2;
            else l = mid+1;
        }
        else
        {
            if((mid+2) <= r && (r-(mid+2)+1) % 2 != 0) l = mid+2;
            else r = mid-1;
        }
        
    }

    if(l==r) duplicate = nums[l];

    return duplicate;
}   