
#include<bits/stdc++.h>

using namespace std;

int main()
{


    getchar();
    return 0;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    int lim = pow(2,nums.size())-1;
    vector<vector<int>> subsets;
    for(int csM = 0; csM <= lim; ++csM)
    {
        subsets.push_back(vector<int>());
        vector<vector<int>>::reverse_iterator currSubset = subsets.rbegin();

        for(int i = 0; i < nums.size(); ++i)
        {
            if(csM & (1 << i))
                currSubset->push_back(nums[i]);
        }
        sort(currSubset->begin(), currSubset->end());
    }

    //Identifying duplicate subsets
    unordered_set<int> isDuplicate;
    for(int i = 0; i < subsets.size(); ++i)
    {
        for(int j = i+1; j < subsets.size(); ++j)
        {
            if(subsets[i].size() != subsets[j].size())
                continue;

            int p1 = 0;
            int p2 = 0;
            while(p1 < subsets[i].size())
            {
                if(subsets[i][p1] != subsets[j][p2])
                    break;
                p1++;
                p2++;
            }

            if(p1 == subsets[i].size())
                isDuplicate.insert(j);
        }
    }

    vector<vector<int>> uniqueSubsets;
    for(int i = 0; i < subsets.size(); ++i)
    {
        if(isDuplicate.find(i) == isDuplicate.end())
            uniqueSubsets.push_back(subsets[i]);
    }

    return uniqueSubsets;   
}