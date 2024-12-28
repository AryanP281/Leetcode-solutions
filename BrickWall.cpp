
#include<bits/stdc++.h>

using namespace std;

int leastBricks(vector<vector<int>>& wall);

int main()
{

    vector<vector<int>> wall = {{1},{1},{1}};
    cout << leastBricks(wall);

    getchar();

    return 0;
}

int leastBricks(vector<vector<int>>& wall) 
{
    unordered_map<int,int> gaps;

    for(int r = 0; r < wall.size(); ++r)
    {
        int gap = 0;
        for(int c = 0; c < wall[r].size()-1; ++c)
        {
            gap += wall[r][c];
            gaps[gap] += 1;
        }
    }

    int minBricks = wall.size();
    for(unordered_map<int,int>::iterator itr = gaps.begin(); itr != gaps.end(); ++itr)
    {
        minBricks = min(minBricks, (int)wall.size()-itr->second);
    }

    return minBricks;
}