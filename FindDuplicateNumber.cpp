
#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums);

int main()
{
    vector<int> arr = {3,1,3,4,2};
    cout << findDuplicate(arr);

    getchar();
    return 0;
}

int findDuplicate(vector<int>& nums) 
{
    int tortoise = 0;
    int hare = 0;

    do
    {
        hare = nums[nums[hare]];
        tortoise = nums[tortoise];
    } while (hare != tortoise);

    tortoise = 0;
    while(hare != tortoise)
    {
        hare = nums[hare];
        tortoise = nums[tortoise];
    }
    
    return hare; 
}