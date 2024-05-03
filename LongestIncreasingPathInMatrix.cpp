
#include<bits/stdc++.h>

using namespace std;

int longestIncreasingPath(vector<vector<int>>& matrix);
int getBestPath(int currR, int currC, vector<vector<int>>& matrix, int* paths);
int twoDto1D(int r, int c, int nC);

int main()
{

    vector<vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}};
    cout << longestIncreasingPath(matrix);

    getchar();
    return 0;
}

int longestIncreasingPath(vector<vector<int>>& matrix) 
{
    int* paths = new int[matrix.size()*matrix[0].size()]();
    fill_n(paths, matrix.size()*matrix[0].size(), -1);

    int result = 0;
    for(int r = 0; r < matrix.size(); ++r)
    {
        for(int c = 0; c < matrix[r].size(); ++c)
        {
            result = max(result, getBestPath(r,c,matrix,paths));
        }
    }

    delete[] paths; 

    return result + 1;
}

int getBestPath(int currR, int currC, vector<vector<int>>& matrix, int* paths)
{
    int cellIdx = twoDto1D(currR, currC, matrix[currR].size());

    if(paths[cellIdx] != -1)
        return paths[cellIdx];

    const int NEIGHBOURS[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int nR, nC;
    paths[cellIdx] = 0;
    for(int i = 0; i < 4; ++i)
    {
        nR = currR + NEIGHBOURS[i][0];
        nC = currC + NEIGHBOURS[i][1];

        if(nR >= 0 && nR < matrix.size() && nC >= 0 && nC < matrix[0].size())
        {
            if(matrix[nR][nC] > matrix[currR][currC])
                paths[cellIdx] = max(paths[cellIdx], getBestPath(nR, nC, matrix, paths)+1);
        }
    }

    return paths[cellIdx];
}

int twoDto1D(int r, int c, int nC)
{
    return (r*nC + c);
}