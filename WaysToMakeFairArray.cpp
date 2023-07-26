#include<bits/stdc++.h>

using namespace std;

int waysToMakeFair(vector<int>& nums);

int main()
{
    vector<int> nums = {1};
    cout << waysToMakeFair(nums);

    getchar();
    return 0;
}

int waysToMakeFair(vector<int>& nums) 
{
    /*Odd = prev_odd + (final_even - current_even)
    Even = prev_even + (final_odd - currOdd)*/

    int n = nums.size();
    
    pair<int,int>* cumSums = new pair<int,int>[n];
    cumSums[0] = pair<int,int>(0,nums[0]);
    for(int a = 1; a < n; ++a)
    {
        if(a % 2 == 0)
            cumSums[a] = pair<int,int>(cumSums[a-1].first, cumSums[a-1].second+nums[a]);
        else
            cumSums[a] = pair<int,int>(cumSums[a-1].first+nums[a], cumSums[a-1].second);
    }

    int oddSum = cumSums[n-1].second - nums[0];
    int evenSum = cumSums[n-1].first;
    int count = 1*(oddSum == evenSum);
    for(int a = 1; a < n-1; ++a)
    {
        oddSum = cumSums[a-1].first + (cumSums[n-1].second - cumSums[a].second);
        evenSum = cumSums[a-1].second + (cumSums[n-1].first - cumSums[a].first);
        count += 1*(oddSum == evenSum);
    }
    oddSum = cumSums[n-2].first;
    evenSum = cumSums[n-2].second;
    count += 1*(oddSum==evenSum);

    delete[] cumSums; 

    return count;
}

/*
[2,1,6,4],[(o,e)]=[(0,2),(1,2),(1,8),(5,8)],o0=5,e0=8
[1,6,4],o=e0-2=6,e=o0=5
[2,6,4],o=8-2=6,e=2+(5-1)=6
[2,1,4],o=1+(8-8)=1,e=2+(5-1)=6
[2,1,6],o=1,e=8

[2,1,6,4,3],[(0,2),(1,2),(1,8),(5,8),(5,11)]
[1,6,4,3],o=e0=11-2=9,e=o0=5
[2,6,4,3],o=0+11-2=9,e=2+5-1=6
[2,1,4,3],o=1+(11-8)=4,e=2+(5-1)=6
[2,1,6,3],o=1+(11-8)=4,e=8+(5-5)=8
[2,1,6,4],o=5,e=11-3=8
*/