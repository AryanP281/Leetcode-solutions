
#include<bits/stdc++.h>

using namespace std;

int arrayNesting(vector<int>& nums);
int dfs(int i, vector<int>& nums, int* setLengths, bool* visited);

int main()
{
    vector<int> nums = {0,1,2};
    cout << arrayNesting(nums);

    getchar();
    return 0;
}

int arrayNesting(vector<int>& nums) 
{
    int* setLengths = new int[nums.size()]();
    bool* visited = new bool[nums.size()]();

    int maxSetSize = 0;
    for(int a = 0; a < nums.size(); ++a)
    {
        if(setLengths[a])
            continue;

        maxSetSize = max(maxSetSize, dfs(a,nums,setLengths,visited));
    }

    delete[] visited;
    delete[] setLengths;   

    return maxSetSize;
}

int dfs(int i, vector<int>& nums, int* setLengths, bool* visited)
{
    if(visited[i])
        return 0;
    else if(setLengths[i])
        return setLengths[i];

    visited[i] = true;
    setLengths[i] = 1+dfs(nums[i], nums, setLengths, visited);
    visited[i] = false;

    return setLengths[i];
}