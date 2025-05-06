
#include<bits/stdc++.h>

using namespace std;

void rotate(vector<int>& nums, int k);

int main()
{
    vector<int> nums = {-1,-100,3,99};
    rotate(nums, 2);

    getchar();
    return 0;
}

void rotate(vector<int>& nums, int k) 
{
    const int N = nums.size();

    reverse(nums.begin(), nums.end());
    vector<int>::iterator boundary = nums.begin();
    for(int i = 0; i < (k%N); ++i)
    {
        boundary++;
    }

    reverse(nums.begin(), boundary);
    reverse(boundary, nums.end());
}