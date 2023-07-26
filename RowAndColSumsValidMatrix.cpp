
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
{
    typedef vector<vector<int>> Matrix;

    Matrix matrix = Matrix(rowSum.size(), vector<int>(colSum.size(), 0));

    int r = 0;
    int c = 0;
    while(r < rowSum.size() && c < colSum.size())
    {
        if(rowSum[r] < colSum[c])
        {
            matrix[r][c] = rowSum[r];
            colSum[c] -= rowSum[r];
            r++;
        }
        else
        {
            matrix[r][c] = colSum[c];
            rowSum[r] -= colSum[c];
            ++c;
        }
        
    }

    return matrix;   
}