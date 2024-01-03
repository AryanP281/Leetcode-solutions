
#include<bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums);

int main()
{

    vector<int> nums = {-3,5,-1,0,6,-9};
    cout << maxProduct(nums);

    getchar();
    return 0;
}

int maxProduct(vector<int>& nums) 
{
    int firstNeg[2] = {-1,-1};

    int currProd = 1;
    int maxProd = INT_MIN;

    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == 0)
        {
            currProd = 1;
            firstNeg[0] = -1;
            maxProd = max(maxProd, 0);
            continue;
        }

        currProd *= nums[i];
        maxProd = max(maxProd, currProd);
        if(currProd < 0)
        {
            if(firstNeg[0] == -1)
            {
                firstNeg[0] = i;
                firstNeg[1] = currProd;
            }
            else
                maxProd = max(maxProd, currProd / firstNeg[1]);
        }
    }

    return maxProd;
}