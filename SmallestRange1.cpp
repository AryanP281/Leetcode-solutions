
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

int smallestRangeI(vector<int>& A, int K) 
{
    sort(A.begin(), A.end());
    int maxDiff = abs((A[A.size()] + K) - (A[0] - K));   
}