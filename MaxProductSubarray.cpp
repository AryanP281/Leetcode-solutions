
#include<bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums);

int main()
{
    vector<int> nums = {-2};
    cout << maxProduct(nums);

    getchar();
    return 0;
}

int maxProduct(vector<int>& nums) 
{
    nums.push_back(0);

    int l = 0;
    int r = 0;
    int maxProd = INT_MIN;
    int currProd = 1;
    for(; r < nums.size(); ++r)
    {
        if(r != nums.size()-1)
            maxProd = max(maxProd, nums[r]);
            
        if(!nums[r])
        {
            while(l < r-1)
            {
                currProd /= nums[l];
                maxProd = max(maxProd, currProd);
                l++;
            }
            l = r+1;
            currProd = 1;
        }
        else
        {
            currProd *= nums[r];
            maxProd = max(maxProd, currProd);
        }
    }

    return maxProd;
}