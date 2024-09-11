
#include<bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> matrix = {{100}};
    rotate(matrix);
    for(int r = 0; r < matrix.size(); ++r)
    {
        for(int c = 0; c < matrix[r].size(); ++c)
        {
            cout << matrix[r][c] << ',';
        }
        cout << '\n';
    }


    getchar();
    return 0;
}

void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    for(int r = 0; r <= floor((int)n / 2.0); ++r)
    {
        for(int c = r; c < n-r-1; ++c)
        {
            int rn = c;
            int cn = n - 1 - r;
            int prevVal = matrix[r][c];
            int currVal;
            for(int i = 0; i < 4; ++i, prevVal=currVal)
            {
                currVal = matrix[rn][cn];
                matrix[rn][cn] = prevVal;
                
                int temp = rn;
                rn = cn;
                cn = n - 1 - temp;
            } 
        }
    }        
}