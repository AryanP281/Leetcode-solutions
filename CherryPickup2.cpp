
#include<bits/stdc++.h>

using namespace std;

int cherryPickup(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> grid = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    cout << cherryPickup(grid);

    getchar();
    return 0;
}

int cherryPickup(vector<vector<int>>& grid) 
{
    typedef vector<vector<int>> Matrix;

    int n = grid.size();
    int m = grid[0].size();

    Matrix* prevRowMaxCheeries = new Matrix(m, vector<int>(m,0));
    for(int r = 0; r < m; ++r)
    {
        for(int c = 0; c < m; ++c)
        {
            (*prevRowMaxCheeries)[r][c] = (grid.rbegin()->at(r) + grid.rbegin()->at(c))*(r != c) + (grid.rbegin()->at(r))*(r==c);
        }
    }

    Matrix* currRowMaxCheeries = new Matrix(m,vector<int>(m,0));
    int newCheeriesCount;
    for(int r = n-2; r >= 0; --r)
    {
        for(int c1 = 0; c1 < m; ++c1)
        {
            for(int c2 = 0; c2 < m; ++c2)
            {
                for(int n1 = c1-1*(c1!=0); n1 < m && n1 <= c1+1; ++n1)
                {
                    for(int n2 = c2-1*(c2!=0); n2 < m && n2 <= c2+1; ++n2)
                    {
                        newCheeriesCount = (*prevRowMaxCheeries)[n1][n2] + (grid[r][c1] + grid[r][c2])*(c1 != c2) + 
                        (grid[r][c1])*(c1==c2);
                        (*currRowMaxCheeries)[c1][c2] = max((*currRowMaxCheeries)[c1][c2], newCheeriesCount);
                    }
                }
            }
        }

        Matrix* temp = prevRowMaxCheeries;
        prevRowMaxCheeries = currRowMaxCheeries;
        delete temp;
        currRowMaxCheeries = new Matrix(m,vector<int>(m,0));
    }

    int maxCheeries = (*prevRowMaxCheeries)[0][m-1];
    delete prevRowMaxCheeries;

    return maxCheeries;
}