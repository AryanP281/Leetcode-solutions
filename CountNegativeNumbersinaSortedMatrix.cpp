/*
#include<iostream>
#include<vector>

using namespace std;

int negs;
int lastPosIndex;

int countNegatives(vector<vector<int>>& grid);
void negsInRow(vector<int>& row, int l, int r);

void main()
{
    int gridArr[4][5] = { {4,3,3,1,1}, {1,0,0,-1,-1}, {-2,-2,-2,-2,-3}, {-3,-3,-3,-3,-3} };
    vector<vector<int>> gridVec;
    for (int r = 0; r < 4; ++r)
    {
        gridVec.push_back(vector<int>());
        for (int c = 0; c < 5; ++c)
        {
            gridVec[r].push_back(gridArr[r][c]);
        }
    }

    cout << countNegatives(gridVec);
}

int countNegatives(vector<vector<int>>& grid)
{
    for (int r = 0; r < grid.size(); ++r)
    {
        lastPosIndex = 0;
        negsInRow(grid[r], 0, grid[r].size() - 1);
    }

    return negs;
}

void negsInRow(vector<int>& row, int l, int r)
{
    if (r == l)
    {
        negs += (row.size() - r)*(row[l] < 0);
        return;
    }

    int m = (r - l) / 2;
    
    if (row[l + m] >= 0)
    {
        lastPosIndex = l + m;
        negsInRow(row, l + m + 1, r);
    }
    else
    {
        if((l+m == 0) || row[l+m-1] >= 0)
        {
            negs += row.size() - (l + m);
        }
        else negsInRow(row, lastPosIndex, l + m - 1);
    }
}*/