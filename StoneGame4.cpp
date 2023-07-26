
#include<bits/stdc++.h>

using namespace std;

bool winnerSquareGame(int n);

int main()
{
    bool canWin = winnerSquareGame(5);
    cout << (canWin ? "True":"False");

    getchar();
    return 0;
}

bool winnerSquareGame(int n) 
{
    vector<bool> canWin = vector<bool>(n, true);

    int nextRoot = 2;
    for(int i = 2; i <= n; ++i)
    {
        if(i == nextRoot*nextRoot)
        {
            nextRoot++;
            continue;
        }

        for(int j = 1; j*j < i && canWin[i-1]; ++j)
        {
            int sq = j*j;
            canWin[i-1] = (canWin[i-1] & canWin[i-sq-1]);
        }
        canWin[i-1] = !canWin[i-1];
    }

    return canWin[n-1];
}