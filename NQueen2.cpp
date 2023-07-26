
#include<bits/stdc++.h>

using namespace std;

int totalNQueens(int n);
void getNQueens(int i, int n, int16_t colMask, unordered_set<int>& lrDiagonals, unordered_set<int>& rlDiagonals, int* solsCount);

int main()
{
    cout << totalNQueens(4);

    getchar();
    return 0;
}

int totalNQueens(int n) 
{
    if(n == 1)
        return 1;
    else if(n <= 3)
        return 0;

    int16_t columnMask = 0;
    unordered_set<int> lrDiagonals;
    unordered_set<int> rlDiagonals;

    int solsCount = 0;
    getNQueens(0, n, columnMask, lrDiagonals, rlDiagonals, &solsCount);

    return solsCount;    
}

void getNQueens(int i, int n, int16_t colMask, unordered_set<int>& lrDiagonals, unordered_set<int>& rlDiagonals, int* solsCount)
{
    if(i >= n)
    {
        *solsCount += 1;
        return;
    }

    int lrIntercept, rlIntercept;
    int16_t newMask;
    for(int a = 0; a < n; ++a)
    {
        if((colMask & 1 << a) != 0)
            continue;

        //Getting lr intercept
        lrIntercept = -(a+1) + (i+1);
        if(lrDiagonals.count(lrIntercept))
            continue;

        //Getting rl intercept
        rlIntercept = (a-1) + (i+1);
        if(rlDiagonals.count(rlIntercept))
            continue;       

        newMask = colMask | (1 << a);
        lrDiagonals.insert(lrIntercept);
        rlDiagonals.insert(rlIntercept);

        getNQueens(i+1, n, newMask, lrDiagonals, rlDiagonals, solsCount);

        lrDiagonals.erase(lrIntercept);
        rlDiagonals.erase(rlIntercept);
    }
}