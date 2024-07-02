#include<bits/stdc++.h>

using namespace std;
int minimumArea(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> grid = {{0,1}};
    minimumArea(grid);

    getchar();
    return 0;
}

int minimumArea(vector<vector<int>>& grid) 
{
    int minR = grid.size()-1;  
    int minC = grid[0].size()-1;  
    int maxR = 0;
    int maxC = 0;

    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            if(grid[r][c] == 1)
            {
                minR = min(minR, r);
                maxR = max(maxR, r);
                minC = min(minC, c);
                maxC = max(maxC, c);
            }
        }
    }

    int minArea = (maxR - minR + 1)*(maxC-minC+1);

    return minArea;    
}