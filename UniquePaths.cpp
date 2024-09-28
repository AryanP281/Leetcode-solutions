
#include<bits/stdc++.h>

using namespace std;

const int NEIGHBOURS[2][2] = {{0,1},{1,0}};

int uniquePaths(int m, int n);
int getPaths(int r, int c, int m, int n, vector<vector<int>>& paths);

int main()
{
    cout << uniquePaths(3,2);

    getchar();
    return 0;
}

int uniquePaths(int m, int n) 
{
    vector<vector<int>> paths;
    for(int r = 0; r < m; ++r)
    {
        paths.push_back(vector<int>(n, -1));
    }
    paths[m-1][n-1] = 1;

    return getPaths(0,0,m,n,paths);
}

int getPaths(int r, int c, int m, int n, vector<vector<int>>& paths)
{
    if(r >= m || c >= n)
        return 0;
    else if(paths[r][c] != -1)
        return paths[r][c];

    paths[r][c] = 0;
    for(int i = 0; i < 2; ++i)
    {
        int nR = r + NEIGHBOURS[i][0];
        int nC = c + NEIGHBOURS[i][1];

        if(nR < m && nC < n)
            paths[r][c] += getPaths(nR, nC, m, n, paths);
    }

    return paths[r][c];
}