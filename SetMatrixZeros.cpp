
#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Matrix;

void setZeros(Matrix& matrix);
void getOrderedElements(Matrix& matrix, set<int>& elements);
int* getDelimiters(set<int>& elements);
void setRow(int r, Matrix& mtrx, int* delims);
void setCol(int c, Matrix& mtrx, int* delims);

int main()
{
    Matrix mtrx = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeros(mtrx);

    for(auto r : mtrx)
    {
        for(auto c : r)
        {
            cout << c << ' ';
        }
        cout << '\n';
    }

    getchar();
    return 0;
}

void setZeros(Matrix& matrix)
{
    set<int> elements;
    getOrderedElements(matrix, elements);

    int* delimiters = getDelimiters(elements);

    for(int r = 0; r < matrix.size(); ++r)
    {
        for(int c = 0; c < matrix[r].size(); ++c)
        {
            if(matrix[r][c] == 0)
            {
                if(matrix[r][0] == delimiters[1])
                    matrix[r][0] = delimiters[2];
                else if(matrix[r][0] != delimiters[2])
                    matrix[r][0] = delimiters[0];

                if(matrix[0][c] == delimiters[0])
                    matrix[0][c] = delimiters[2];
                else if(matrix[0][c] != delimiters[2])
                    matrix[0][c] = delimiters[1];
            }
        }
    }

    for(int r = 0; r < matrix.size(); ++r)
    {
        if(matrix[r][0] == delimiters[0] || matrix[r][0] == delimiters[2])
            setRow(r, matrix, delimiters);
    }

    for(int c = 0; c < matrix[0].size(); ++c)
    {
        if(matrix[0][c] == delimiters[1])
            setCol(c, matrix, delimiters);
    }

    delete[] delimiters;
}

void getOrderedElements(Matrix& matrix, set<int>& elements)
{
    for(int r = 0; r < matrix.size(); ++r)
    {
        for(int c = 0; c < matrix[r].size(); ++c)
        {
            elements.insert(matrix[r][c]);
        }
    }
}

int* getDelimiters(set<int>& elements)
{
    int* delimiters = new int[3];
    elements.insert(INT_MIN);
    elements.insert(INT_MAX);

    set<int>::iterator itr = elements.begin();
    set<int>::iterator nxt = itr;
    nxt++;
    int i = 0;
    while(i < 3)
    {
        for(int d = *itr + 1; d < *nxt && i < 3; ++d)
        {
            if(d == 0)
                continue;

            delimiters[i++] = d;
        }
    }

    return delimiters;
}

void setRow(int r, Matrix& mtrx, int* delims)
{
    if(r < 0 || r >= mtrx.size())
        return;

    for(int c = 0; c < mtrx[r].size(); ++c)
    {
        if(mtrx[r][c] == delims[1])
            setCol(c, mtrx, delims);
        else if(mtrx[r][c] == delims[2])
        {
            mtrx[r][c] = delims[1];
            setCol(c,mtrx,delims);
        }
        mtrx[r][c] = 0;
    }
}

void setCol(int c, Matrix& mtrx, int* delims)
{
    if(c < 0 || c >= mtrx[0].size())
        return;

    for(int r = 0; r < mtrx.size(); ++r)
    {
        if(mtrx[r][c] == delims[0])
            setRow(r, mtrx, delims);
        else if(mtrx[r][c] == delims[2])
        {
            mtrx[r][c] = delims[0];
            setRow(r,mtrx,delims);
        }
        mtrx[r][c] = 0;
    }
}
