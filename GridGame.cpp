
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> Vec; 

long long gridGame(vector<vector<int>>& grid);

int main()
{

    //vector<vector<int>> grid = {{20,3,20,17,2,12,15,17,4,15},{20,10,13,14,15,5,2,3,14,3}};
    vector<vector<int>> grid = {{1},{2}};
    cout << gridGame(grid);

    getchar();
    return 0;
}

long long gridGame(vector<vector<int>>& grid) 
{
    const int n = grid[0].size();

    if(n == 1)
        return 0;

    vector<ll> topRowSums(n, 0);
    vector<ll> bottomRowSums(n, 0);

    topRowSums[n-1] = grid[0][n-1];
    bottomRowSums[0] = grid[1][0];
    for(int i = 1; i < n; ++i)
    {
        topRowSums[n-1-i] = topRowSums[n-i] + grid[0][n-1-i];
        bottomRowSums[i] = bottomRowSums[i-1] + grid[1][i];
    }

    ll secBotScore = min(topRowSums[1], bottomRowSums[n-2]);
    for(int i = 1; i < n-1; ++i)
    {
        secBotScore = min(secBotScore, max(topRowSums[i+1], bottomRowSums[i-1]));
    }

    return secBotScore;
}