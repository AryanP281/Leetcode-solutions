
#include<bits/stdc++.h>

using namespace std;

vector<int> countBits(int n);

int main()
{
    countBits(5);

    getchar();
    return 0;
}

vector<int> countBits(int n) 
{
    /*
        if (i-1) is even i.e i is odd, bits[i] = bits[i-1] + 1
        if(i-1) is odd i.e i is even, v1 = ~(i-1), v2 = v1 & (v1-1), v3 = v1 ^ v2, j = log2(v3), bits[i] = bits[i-1] - j + 1
    */

    vector<int> bits = {0};
    for(int i = 1; i <= n; ++i)
    {
        if((i%2))
            bits.push_back(bits[bits.size()-1]+1);
        else
        {
            int v1 = ~(i-1);
            int v2 = v1 & (v1-1);
            int v3 = v1 ^ v2;
            int j = floor(log2(v3));
            bits.push_back(bits[bits.size()-1] - j + 1);
        }
    }

    return bits;
}