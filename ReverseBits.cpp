
#include<bits/stdc++.h>

using namespace std;

uint32_t reverseBits(uint32_t n);

int main()
{
    cout << reverseBits(4294967293);

    getchar();
    return 0;
}

uint32_t reverseBits(uint32_t n) 
{
    uint32_t reversed = 0;

    for(int i = 0; i < 32; ++i)
    {
        uint32_t mask = (n>>(31-i)) & 1;
        reversed |= (mask << i);
    }

    return reversed;
}