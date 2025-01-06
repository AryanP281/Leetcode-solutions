
#include<bits/stdc++.h>

using namespace std;

class NumMatrix 
{
private:
    vector<vector<int>> rectSums;

public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int** colPrefixSums = new int*[matrix[0].size()];
        for(int c = 0; c < matrix[0].size(); ++c)
        {
            colPrefixSums[c] = new int[matrix.size()];
            colPrefixSums[c][0] = matrix[0][c];
            for(int r = 1; r < matrix.size(); ++r)
            {
                colPrefixSums[c][r] = colPrefixSums[c][r-1] + matrix[r][c];
            }
        }

        for(int r = 0; r < matrix.size(); ++r)
        {
            rectSums.push_back(vector<int>());
            rectSums[r].push_back(colPrefixSums[0][r]);
            for(int c = 1; c < matrix[r].size(); ++c)
            {
                rectSums[r].push_back(*rectSums[r].rbegin() + colPrefixSums[c][r]);
            }
        }
        
        for(int c = 0; c < matrix[0].size(); ++c)
        {
            delete[] colPrefixSums[c];
        }
        delete[] colPrefixSums;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int result = this->rectSums[row2][col2];
        if(col1 != 0)
            result -= this->rectSums[row2][col1-1];
        if(row1 != 0)
            result -= this->rectSums[row1-1][col2];
        if(row1 != 0 && col1 != 0)
            result += this->rectSums[row1-1][col1-1];

        return result;
    }
};

int main()
{

    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(0,0,2,2) << endl;
    cout << numMatrix.sumRegion(2,1,4,3) << endl;
    cout << numMatrix.sumRegion(1,1,2,2) << endl;
    cout << numMatrix.sumRegion(1,2,2,4) << endl;

    getchar();
    return 0;
}

