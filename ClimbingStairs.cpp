
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

int climbStairs(int n) 
{
    if(n == 1)
        return 1;

    int prevs[2] = {1,2};

    int curr = prevs[1];
    for(int i = 3; i <= n; prevs[0] = prevs[1],prevs[1]=curr,++i)
    {
        curr = prevs[0] + prevs[1];
    }

    return curr;        
}