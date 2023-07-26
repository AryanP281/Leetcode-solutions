
#include<bits/stdc++.h>

using namespace std;

int integerBreak(int n);
int64_t getPower(int x, int y);

int main()
{
    cout << integerBreak(10);

    getchar();
    return 0;
}

int integerBreak(int n) 
{
    int64_t maxProduct = 0;
    int64_t currProduct;

    for(int k = 2; k <= n; ++k)
    {
        int quotent = floor(n / k);
        int remainder = n % k;

        currProduct = getPower(quotent+1,remainder) * getPower(quotent, k - remainder);

        if(currProduct > maxProduct) maxProduct = currProduct;
    }

    return maxProduct;   
}

int64_t getPower(int x, int y)
{
    if(y == 0)
        return 1;
    else if(y == 1)
        return x;

    if(y % 2)
        return getPower(x,y-1) * x;
    
    int64_t root = getPower(x, y/2);

    return root * root;
}