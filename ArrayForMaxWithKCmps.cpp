
#include<bits/stdc++.h>

using namespace std;

typedef long long lli;

const lli MOD = 1e9 + 7;

struct State
{
    int n;
    int m;
    int k;

    State(int n, int m, int k)
    {
        this->n = n;
        this->m = m;
        this->k = k;
    }
};

lli numOfArrays(int n, int m, int k);
lli getArrays(State currState, State finalState, vector<vector<vector<lli>>>& lookupTable);

int main()
{
    cout << numOfArrays(37,17,7);

    getchar();
    return 0;
}

lli numOfArrays(int n, int m, int k) 
{
    vector<vector<vector<lli>>> lookupTable(n, vector<vector<lli>>(m+1, vector<lli>(k+1,-1)));

    return getArrays(State(0,0,k), State(n,m,k), lookupTable);
}

lli getArrays(State currState, State finalState, vector<vector<vector<lli>>>& lookupTable)
{
    if(currState.n == finalState.n)
        return 1*(currState.k == 0);
    else if(currState.k > finalState.n-currState.n)
        return 0;
    else if(lookupTable[currState.n][currState.m][currState.k] != -1)
        return lookupTable[currState.n][currState.m][currState.k];

    lli* tableEntry = &lookupTable[currState.n][currState.m][currState.k];
    *tableEntry = 0;
    int i = 1*(currState.k != finalState.n - currState.n) + (currState.m + 1)*(currState.k == finalState.n - currState.n);
    for(; i <= finalState.m; ++i)
    {
        if(i > currState.m && currState.k == 0)
            break;
        
        *tableEntry = (*tableEntry + getArrays(State(currState.n+1, max(i, currState.m), currState.k - 1*(i > currState.m)), finalState, lookupTable)) % MOD;
    }

    return *tableEntry;
}

/*
n=3,m=5,k=2

{[(1,1

mx=1,_k=1
[1,1,2], [1,1,3], [1,1,4], [1,1,5]
mx=2, _k=0
[1,2,1], [1,2,2]
mx=3, _k=0
[1,3,1], [1,3,2], [1,3,3]
mx=4,_k=0
[1,4,1], [1,4,2], [1,4,3], [1,4,4]
mx=5,_k=0
[1,5,1], [1,5,2], [1,5,3], [1,5,4], [1,5,5]
mx=2,_k=1
[2,1,3], [2,1,4], [2,1,5]
mx=2, _k=1
[2,2,3],[2,2,4],[2,2,5]
mx=3, _k=0
[2,3,1], [2,3,2], [2,3,3]
mx=4,_k=0
[2,4,1], [2,4,2], [2,4,3], [2,4,4]
mx=5,_k=0
[2,5,1], [2,5,2], [2,5,3], [2,5,4], [2,5,5]
mx=3,_k=1
[3,1,4], [3,1,5]
mx=3, _k=1
[3,2,4], [3,2,5]
mx=3, _k=1
[3,3,4], [3,3,5]
mx=4,_k=0
[3,4,1], [3,4,2], [3,4,3], [3,4,4], [3,4,5]
mx=5, _k=0
[3,5,1], [3,5,2], [3,5,3], [3,5,4], [3,5,5]
mx=4,_k=1
[4,1,5]
mx=4, _k=1
[4,2,5]
mx=4, _k=1
[4,3,5]
mx=4, _k=1
[4,4,5]
mx=5, _k=0
[4,5,1], [4,5,2], [4,5,3], [4,5,4], [4,5,5]
*/