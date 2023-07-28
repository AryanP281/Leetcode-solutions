
#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target);

int main()
{
    vector<int> nums = {2,3,4};
    vector<int> indices = twoSum(nums, 6);
    cout << indices[0] << ',' << indices[1] << '\n';

    getchar();
    return 0;
}

vector<int> twoSum(vector<int>& numbers, int target) 
{
    vector<int> indices = {0,0};

    int l = 0;
    int r = numbers.size()-1;
    for(; l < r;)
    {
        if(numbers[l] + numbers[r] == target)
        {
            indices[0] = l+1;
            indices[1] = r+1;
            break;
        }
        else if(numbers[l] + numbers[r] < target)
            l++;
        else
            r--;
    }        
    
    return indices;
}