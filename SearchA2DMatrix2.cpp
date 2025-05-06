
#include<bits/stdc++.h>

using namespace std;

int main()
{


    getchar();

    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int r = 0;
    int c = 0;
    while(c < matrix[r].size()-1 && matrix[r][c+1] <= target)
        c++;

    for(; r < matrix.size(); r++)
    {
        while(matrix[r][c] > target && c > 0)
            c--;

        if(matrix[r][c] > target)
            return false;
        else if(matrix[r][c] == target)
            return true;
    }

    return false;
}