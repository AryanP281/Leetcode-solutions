
#include<bits/stdc++.h>

using namespace std;

int numRollsToTarget(int d, int f, int target) ;

const long long MOD = 1000000007;

int main()
{

    cout << numRollsToTarget(30,30,500);

    getchar();
    return 0;
}

int numRollsToTarget(int d, int f, int target) 
{
    long long** ways = new long long*[target];
    for(int a = 0; a < target; ++a)
    {
        ways[a] = new long long[d]();
        ways[a][0] = 1*(a<f);
        for(int b = 1; b < d; ++b)
        {
            if(a > ((b+1)*f))
            {
                ways[a][b] = 0;
                continue;
            }
            
            for(int k = 0; k < a && k < f; ++k)
            {
                ways[a][b] += ways[a-k-1][b-1];
                ways [a][b] %= MOD;
            }
        }
    }

    int waysToTarget = ways[target-1][d-1];

    for(int a = 0; a < target; ++a)
    {
        delete[] ways[a];
    }   
    delete[] ways;

    return waysToTarget;
}