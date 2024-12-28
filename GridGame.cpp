
#include<bits/stdc++.h>

using namespace std;

long long gridGame(vector<vector<int>>& grid);
void getPathCosts(vector<vector<int>>& grid, int64_t** pathCosts, const int N);

int main()
{
    vector<vector<int>> grid = {{20,3,20,17,2,12,15,17,4,15},{20,10,13,14,15,5,2,3,14,3}};
    cout << gridGame(grid);

    getchar();

    return 0;
}

long long gridGame(vector<vector<int>>& grid) 
{
    const int N = grid[0].size();

    if(N == 1)
        return 0;

    long long* row0Sum = new long long[N];
    row0Sum[N-1] = grid[0][N-1];
    for(int i = N-2; i > 0; --i)
    {
        row0Sum[i] = row0Sum[i+1] + grid[0][i];
    }
    row0Sum[0] = row0Sum[1];

    long long* row1Sum = new long long[N];
    row1Sum[0] = grid[1][0];
    for(int i = 1; i < N-1; ++i)
    {
        row1Sum[i] = row1Sum[i-1] + grid[1][i];
    }
    row1Sum[N-1] = row1Sum[N-2];

    long long bestScore = INT64_MAX;
    for(int i = 0; i < N; ++i)
    {
        long long currScore = 0;
        if(i != 0)
            currScore = max(currScore, row1Sum[i-1]);
        if(i != N-1)
            currScore = max(currScore, row0Sum[i+1]);
        bestScore = min(bestScore, currScore);
    }

    delete[] row0Sum;
    delete[] row1Sum;

    return bestScore;
}