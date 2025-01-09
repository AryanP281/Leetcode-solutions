
#include<bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int>& nums);

int main()
{
    vector<int> nums = {1,2,3};
    majorityElement(nums);

    getchar();
    return 0;
}

vector<int> majorityElement(vector<int>& nums) 
{
    unordered_map<int,int> candidates;

    //Finding majority element candidates
    unordered_map<int,int>::iterator itr;
    for(int i = 0; i < nums.size(); ++i)
    {
        itr = candidates.find(nums[i]);
        if(itr == candidates.end())
        {
            if(candidates.size() == 2)
            {
                itr = candidates.begin();
                while(itr != candidates.end())
                {
                    unordered_map<int,int>::iterator temp = next(itr);
                    if(itr->second == 1)
                        candidates.erase(itr);
                    else
                        itr->second--;
                    itr = temp;
                }
            }
            else
                candidates[nums[i]] = 1;
        }
        else
            itr->second++;
    }       

    //Checking if majority elements exist
    for(itr = candidates.begin(); itr != candidates.end(); ++itr)
    {
        itr->second = 0;
    }
    for(int i = 0; i < nums.size(); ++i)
    {
        itr = candidates.find(nums[i]);
        if(itr != candidates.end())
            itr->second++;
    }

    vector<int> majorityElements;
    int limit = floor((float)nums.size()/3.0f);
    for(itr = candidates.begin(); itr != candidates.end(); ++itr)
    {
        if(itr->second > limit)
            majorityElements.push_back(itr->first);
    }

    return majorityElements;
}