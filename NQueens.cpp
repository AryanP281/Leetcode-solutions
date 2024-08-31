
#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> solveNQueens(int n);
void find(int currCol, vector<string>& currBoard, bool* occupied, vector<vector<string>>& opts);

int main()
{
    solveNQueens(1);

    getchar();
    return 0;
}

vector<vector<string>> solveNQueens(int n) 
{
    bool* occupied = new bool[n]();

    vector<vector<string>> opts;

    vector<string> currBoard;
    string row = "";
    for(int c = 0; c < n; ++c)
    {
        row += '.';
    }
    for(int r = 0; r < n; ++r)
    {
        currBoard.push_back(row);
    }

    find(0, currBoard, occupied, opts);

    delete[] occupied;

    return opts;        
}

void find(int currCol, vector<string>& currBoard, bool* occupied, vector<vector<string>>& opts)
{
    int n = currBoard.size();
    if(currCol == n)
    {
        opts.push_back(currBoard);
        return;
    }

    for(int r = 0; r < n; ++r)
    {
        if(!occupied[r])
        {
            const int DIAG[4][2] = {{-1,-1},{1,1},{-1,1},{1,-1}};
            bool valid = true;
            for(int d = 0; d < 4 && valid; ++d)
            {
                for(int ir = r, ic = currCol; ir >= 0 && ic >= 0 && ir < n && ic < n; ir += DIAG[d][0], ic += DIAG[d][1])
                {
                    if(currBoard[ir][ic] == 'Q')
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if(valid)
            {
                occupied[r] = true;
                currBoard[r][currCol] = 'Q';
                find(currCol+1, currBoard, occupied, opts);
                occupied[r] = false;
                currBoard[r][currCol] = '.';
            }
        }
    }
}