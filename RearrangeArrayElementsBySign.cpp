
#include<bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums);

int main()
{
    vector<int> nums = {28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31};
    vector<int> modf = rearrangeArray(nums);

    for(int i = 0; i < modf.size(); ++i)
    {
        cout << modf[i] << ", ";
    }

    getchar();
    return 0;
}

vector<int> rearrangeArray(vector<int>& nums) 
{
    vector<int> modfArr(nums.size(), 0);

    int i;
    for(int8_t st = 0; st < 2; ++st)
    {
        i = st;
        for(int j = 0; j < nums.size() && i < nums.size(); ++j)
        {
            if((st == 0 && nums[j] > 0) || (st == 1 && nums[j] < 0))
            {
                modfArr[i] = nums[j];
                i += 2;
            }
        }
    }
    
    return modfArr;
}

