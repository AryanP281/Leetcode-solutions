
#include<bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums);

int main()
{
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> prds = productExceptSelf(nums);

    for(auto x : prds)
    {
        cout << x << ',';
    }

    getchar();
    return 0;
}

vector<int> productExceptSelf(vector<int>& nums) 
{
    vector<int> prd(nums.size(), 1); 

    int32_t cumProd = nums[0];
    for(int i = 1; i < nums.size(); cumProd *= nums[i++])
    {
        prd[i] = cumProd;
    }

    cumProd = *nums.rbegin();
    for(int i = nums.size()-2; i >= 0; cumProd *= nums[i--])
    {
        prd[i] *= cumProd;
    }

    return prd;       
}