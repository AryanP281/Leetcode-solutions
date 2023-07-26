
#include<bits/stdc++.h>

using namespace std;

int numTrees(int n);
int getUniqueBsts(int l, int r, int** lookupTable);

int main()
{
    cout << numTrees(4);
    getchar();
    return 0;
}

int numTrees(int n) 
{
    int** lookupTable = new int*[n];
    for(int a = 0; a < n; ++a)
    {
        lookupTable[a] = new int[n];
        fill_n(lookupTable[a],n,-1);
    }

    int uniqueBsts = getUniqueBsts(0,n-1, lookupTable);

    for(int a = 0; a < n; ++a)
    {
        delete[] lookupTable[a];
    }
    delete[] lookupTable;

    return uniqueBsts;
}

int getUniqueBsts(int l, int r, int** lookupTable)
{
    if(l >= r) return 1;
    else if(lookupTable[l][r] != -1)
        return lookupTable[l][r];

    lookupTable[l][r] = 0;
    for(int k = l; k <= r; ++k)
    {
        int leftBsts = getUniqueBsts(l,k-1,lookupTable);
        int rightBsts = getUniqueBsts(k+1,r,lookupTable);
        lookupTable[l][r] += leftBsts*rightBsts;
    }

    return lookupTable[l][r];
}