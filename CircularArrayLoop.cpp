
#include<bits/stdc++.h>

using namespace std;

bool circularArrayLoop(vector<int>& nums);
bool dfs(int i, bool isPositive, int seqLength, vector<int>& nums, int* traversed, bool* visited);

int main()
{
    vector<int> nums = {-2,-3,-9};

    cout << (circularArrayLoop(nums) ? "true" : "false");

    getchar();
    return 0;
}

bool circularArrayLoop(vector<int>& nums) 
{
    bool* visited = new bool[nums.size()]();
    int* traversed = new int[nums.size()];
    fill_n(traversed, nums.size(), -1);

    bool hasLoop = false;
    for(int i = 0; i < nums.size() && !hasLoop; ++i)
    {
        if(visited[i])
            continue;
        
        hasLoop = dfs(i, nums[i] > 0, 0,nums, traversed, visited);
    }


    delete[] visited;
    delete[] traversed;

    return hasLoop;
}

bool dfs(int i, bool isPositive, int seqLength, vector<int>& nums, int* traversed, bool* visited)
{
    if((isPositive && nums[i] < 0) || (!isPositive && nums[i] > 0))
        return false;
    else if(traversed[i] != -1)
        return seqLength - traversed[i] > 1;
    else if(visited[i])
        return false;
    
    traversed[i] = seqLength;
    
    int nextPos = 0;
    if(isPositive)
        nextPos = (i + nums[i]) % nums.size();
    else
    {
        int steps = (nums[i]*-1) % nums.size();
        nextPos = steps > i ? nums.size()-(steps-i) : i - steps;
    }

    bool hasLoop = dfs(nextPos, isPositive, seqLength+1, nums, traversed, visited);
    traversed[i] = -1;
    visited[i] = true;

    return hasLoop;
}