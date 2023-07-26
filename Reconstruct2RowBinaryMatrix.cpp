
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum);

int main()
{
    vector<int> colSum = {0,1,2,0,0,0,0,0,2,1,2,1,2};
    vector<vector<int>> res = reconstructMatrix(9,2,colSum);

    getchar();
    return 0;
}

vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
{
    int cs = 0;
    cs = accumulate(colsum.begin(),colsum.end(), cs);
    if(cs != (upper+lower))
        return {};

    vector<vector<int>> matrix(2, vector<int>(colsum.size(),0));

    //Colsum = 2
    for(int j = 0; j < colsum.size(); ++j)
    {
        if(colsum[j] == 2)
        {
            matrix[0][j] = 1;
            matrix[1][j] = 1;
            --upper;
            --lower;
        }
    }

    if(upper < 0 || lower < 0)
        return {};

    //Colsum = 1
    for(int j = 0; j < colsum.size(); ++j)
    {
        if(colsum[j] == 1)
        {
            if(upper > 0)
            {
                matrix[0][j] = 1;
                --upper;
            }
            else
            {
                matrix[1][j] = 1;
                --lower;
            }
        }
    }

    if(upper != 0 || lower != 0)
        return {};

    return matrix;
}