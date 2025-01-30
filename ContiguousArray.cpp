
#include<bits/stdc++.h>

using namespace std;

int findMaxLength(vector<int>& nums);

int main()
{
    vector<int> nums = {0,1,0};
    cout << findMaxLength(nums);

    getchar();
    return 0;
}

int findMaxLength(vector<int>& nums) 
{
    /*
        Let Zi = count of zeros uptill nums[i], Oi = count of zeros uptill nums[i].
        For some i < j, if: Oj = Oi+x and Zj = Zj+y.
        Now, if, Oi-Zi = Oj-Zj = Oi+x - Zj - y
        Thus, x = y i.e nums[i..j] has equal number of zeros and ones.
        Therefore, smallest such i will provide the longest contiguous array ending at j. 
    */
    
    unordered_map<int,int> diffs;
    diffs[0] = -1;
    int currCounts[2] = {0,0};
    int maxLen = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        currCounts[nums[i]]++;
        unordered_map<int,int>::iterator itr = diffs.find(currCounts[1] - currCounts[0]);
        if(itr == diffs.end())
            diffs[currCounts[1] - currCounts[0]] = i;
        else
            maxLen = max(maxLen, i-itr->second);
    }

    return maxLen;
}