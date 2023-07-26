
#include<bits/stdc++.h>

using namespace std;

struct State
{
    int i;
    int prevRowCols;

    State(int i, int prevRowCols)
    {
        this->i = i;
        this->prevRowCols = prevRowCols;
    }
};

const int MOD = 1e9+7;

int numOfWays(int n);
int getWays(State state, int n, int**** dp);

int main()
{
    cout << numOfWays(5000);

    getchar();
    return 0;
}

int numOfWays(int n) 
{
    int**** dp = new int***[n];
    for(int a = 0; a < n; ++a)
    {
        dp[a] = new int**[4];
        for(int8_t b = 0; b < 4; ++b)
        {
            dp[a][b] = new int*[4];
            for(int8_t c = 0; c < 4; ++c)
            {
                dp[a][b][c] = new int[4];
                fill_n(dp[a][b][c], 4, -1);
            }
        }
    }

    int totalWays = getWays(State(0,0), n, dp);

    for(int a = 0; a < n; ++a)
    {
        for(int8_t b = 0; b < 4; ++b)
        {
            for(int8_t c = 0; c < 4; ++c)
            {
                delete[] dp[a][b][c];
            }
            delete[] dp[a][b];
        }
        delete[] dp[a];
    }
    delete[] dp;

    return totalWays;
}

int getWays(State state, int n, int**** dp)
{
    if(state.i == n)
        return 1;
    else if(dp[state.i][state.prevRowCols & 3][(state.prevRowCols >>2)&3][(state.prevRowCols >> 4) & 3] != -1)
        return dp[state.i][state.prevRowCols & 3][(state.prevRowCols >>2)&3][(state.prevRowCols >> 4) & 3];

    State nextState(state.i+1,0);
    int val = 0;
    for(int8_t c1 = 1; c1 <= 3; ++c1, nextState.prevRowCols = 0)
    {
        if(c1 == (state.prevRowCols & 3))
            continue;
        nextState.prevRowCols = c1;
        for(int8_t c2 = 1; c2 <= 3; ++c2, nextState.prevRowCols &= 3)
        {
            if(c2 == ((state.prevRowCols >>2)&3) || c2 == c1)
                continue;
            nextState.prevRowCols |= (c2 << 2);
            for(int8_t c3 = 1; c3 <= 3; ++c3, nextState.prevRowCols &= 15)
            {
                if(c3 == ((state.prevRowCols >> 4)&3) || c3 == c2)
                    continue;
                nextState.prevRowCols |= (c3 << 4);

                val = (getWays(nextState, n, dp) + val) % MOD;
            }
        }
    }

    dp[state.i][state.prevRowCols & 3][(state.prevRowCols >>2)&3][(state.prevRowCols >> 4) & 3] = val;

    return val;
}