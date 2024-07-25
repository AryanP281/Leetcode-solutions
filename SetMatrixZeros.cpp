
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

void setZeroes(vector<vector<int>>& matrix) 
{
    //Finding rows and cols
    bool firstRCZero[2] = {false,false};
    for(int r = 0; r < matrix.size(); ++r)
    {
        for(int c = 0; c < matrix[r].size(); ++c)
        {
            if(matrix[r][c] == 0)
            {
                if(r == 0)
                    firstRCZero[0] = true;
                else
                    matrix[r][0] = 0;

                if(c == 0)
                    firstRCZero[1] = true;
                else
                    matrix[0][c] = 0;
            }
        }
    }
    matrix[0][0] = matrix[0][0] == 0 ? 1 : matrix[0][0];

    //Zeroing by row
    for(int r = 0; r < matrix.size(); ++r)
    {
        if(matrix[r][0] != 0)
            continue;
        for(int c = 0; c < matrix[r].size(); ++c)
        {
            matrix[r][c] = 0;
        }
    }

    //Zeroing by col
    for(int c = 0; c < matrix[0].size(); ++c)
    {
        if(matrix[0][c] != 0)
            continue;
        for(int r = 0; r < matrix.size(); ++r)
        {
            matrix[r][c] = 0;
        }
    }

    //Zeroing by first cell
    for(int i = 0; i < 2; ++i)
    {
        if(firstRCZero[i])
        {
            switch(i)
            {
                case 0: fill_n(matrix[0].begin(), matrix[0].size(), 0); break;
                case 1: {
                    for(int r = 0; r < matrix.size(); ++r)
                    {
                        matrix[r][0] = 0;
                    }
                }; break;
            }
        }
    }

}