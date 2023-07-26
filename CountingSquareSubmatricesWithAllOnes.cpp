/*
#include<iostream>
#include<vector>

using namespace std;

struct Vec2D
{
    int x;
    int y;

    Vec2D(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int countSquares(vector<vector<int>>& matrix);
int getSubmatricesCount(vector<vector<int>>& mat, Vec2D start);

void main()
{
    int matVals[5][5] = { {1,1,0,0,1}, {1,0,1,1,1}, {1,1,1,1,1}, {1,0,1,0,1}, {0,0,1,0,1} };
    vector<vector<int>> mat;
    for (int a = 0; a < 5; ++a)
    {
        mat.push_back(vector<int>(matVals[a], matVals[a] + 5));
    }

    cout << countSquares(mat);
}

int countSquares(vector<vector<int>>& matrix)
{
    int squares = 0;
    for (int r = 0; r < matrix.size(); ++r)
    {
        for (int c = 0; c < matrix[r].size(); ++c)
        {
            squares += getSubmatricesCount(matrix, Vec2D(r, c));
        }
    }

    return squares;
}

int getSubmatricesCount(vector<vector<int>>& mat, Vec2D start)
{
    bool valid = mat[start.x][start.y];
    int dim = 0;
    int submatrices = mat[start.x][start.y];

    while (valid && start.x + (++dim) < mat.size() && start.y + dim < mat[start.x].size())
    {
        for (int c = start.y; valid && c <= start.y + dim; ++c)
        {
            valid = mat[start.x + dim][c] && valid;
        }

        for (int r = start.x; valid && r < start.x + dim; ++r)
        {
            valid = mat[r][start.y + dim] && valid;
        }

        submatrices += (valid == true);
    }

    return submatrices;
}
*/