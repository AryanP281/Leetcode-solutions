
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

int hammingWeight(int n) 
{
    int setBits = 0;
    while(n > 0)
    {
        setBits += (n & 1);
        n = n >> 1;
    }     

    return setBits;   
}