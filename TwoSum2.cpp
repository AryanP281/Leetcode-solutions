
#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& arr, int target);

int main()
{
    vector<int> arr = {2,7,11,15};
    twoSum(arr, 9);

    getchar();
    return 0;
}

vector<int> twoSum(vector<int>& arr, int target) 
{
    vector<int> pos = {0,(int)arr.size()-1};

    int sum = 0;
    while(pos[0] != pos[1])
    {
        sum = arr[pos[0]] + arr[pos[1]];
        if(sum == target) break;
        else if(sum < target) pos[0]++;
        else pos[1]--;
    }

    pos[0]++;
    pos[1]++;

    return pos;   
}