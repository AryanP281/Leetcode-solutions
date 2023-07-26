
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec2D;

const Vec2D VECS[4] = {Vec2D(0,-1), Vec2D(-1,0), Vec2D(0,1), Vec2D(1,0)};

int islandPerimeter(vector<vector<int>>& grid) ;

int main()
{
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << islandPerimeter(grid);

    getchar();
    return 0;
}

int islandPerimeter(vector<vector<int>>& grid) 
{
    int perimeter = 0;
    for(int r = 0; r < grid.size(); ++r)
    {
        for(int c = 0; c < grid[r].size(); ++c)
        {
            if(grid[r][c] == 0)
                continue;
            
            for(int a = 0; a < 4; ++a)
            {
                if(r+VECS[a].first < 0 || c+VECS[a].second < 0 || r+VECS[a].first == grid.size() || c+VECS[a].second == grid[r].size() ||
                grid[r+VECS[a].first][c+VECS[a].second] == 0)
                    perimeter++;
            }
        }
    }

    return perimeter;
}