
#include<bits/stdc++.h>

using namespace std;

int getSum(int a, int b);

int main()
{
    cout << getSum(-3,2);

    getchar();
    return 0;
}

int getSum(int a, int b) 
{
    if(b == 0)
        return a;

    return getSum(a^b,((a&b) << 1));
}