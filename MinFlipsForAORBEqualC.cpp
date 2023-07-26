
#include<bits/stdc++.h>

using namespace std;

int minFlips(int a, int b, int c);

int main()
{
    cout << minFlips(1,2,3);
    
    getchar();
    return 0;
}

int minFlips(int a, int b, int c) 
{
    int flips = 0;
    int bitA,bitB,bitC;
    for(int i = 0; i < sizeof(int)*8; ++i, a=(a>>1),b =(b>>1),c=(c>>1))
    {
        bitA = (a & 1);
        bitB = (b & 1);
        bitC = (c & 1);

        if((bitA | bitB) != bitC)
        {
            if(bitC == 1)
                flips++;
            else
            {
                if(bitA && bitB)
                    flips += 2;
                else
                    flips++;
            }
        }
    }

    return flips;
}