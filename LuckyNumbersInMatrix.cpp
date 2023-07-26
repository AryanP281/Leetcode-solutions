/*
#include<iostream>
#include<vector>

using namespace std;

vector<int> luckyNumbers(vector<vector<int>>& matrix);

void main()
{
    int mtrxVals[3][3] = { {3,7,8}, {9,11,13}, {15,16,17} };
    vector<vector<int>> matrix;
    for (int a = 0; a < 3; ++a)
    {
        matrix.push_back(vector<int>(mtrxVals[a], mtrxVals[a] + 3));
    }

    vector<int> ln = luckyNumbers(matrix);
}

vector<int> luckyNumbers(vector<vector<int>>& matrix)
{
    pair<int, int>* rowMins = new pair<int, int>[matrix.size()];
    fill_n(rowMins, matrix.size(), pair<int, int>(INT_MAX, -1));
    pair<int, int>* colMaxs = new pair<int, int>[matrix[0].size()]{ pair<int,int>(0, -1) };

    for (int r = 0; r < matrix.size(); ++r)
    {
        for (int c = 0; c < matrix[r].size(); ++c)
        {
            if (matrix[r][c] < rowMins[r].first)
            {
                rowMins[r].first = matrix[r][c];
                rowMins[r].second = c;
            }
            if (matrix[r][c] > colMaxs[c].first)
            {
                colMaxs[c].first = matrix[r][c];
                colMaxs[c].second = r;
            }
        }
    }

    vector<int> luckyNums;
    for (int r = 0; r < matrix.size(); ++r)
    {
        int c = rowMins[r].second;
        if (rowMins[r].first == colMaxs[c].first) luckyNums.push_back(rowMins[r].first);
    }

    delete[] rowMins;
    delete[] colMaxs;

    return luckyNums;
}
*/