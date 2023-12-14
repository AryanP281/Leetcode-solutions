
#include<bits/stdc++.h>

using namespace std;

int reverse(int x);

int main()
{
    cout << reverse(1534236469);

    getchar();
    return 0;
}

int reverse(int x) 
{
    if(x == 0)
        return 0;
    
    int absX = abs(x);
    int reversed = 0;
    while(absX)
    {
        if(INT_MAX / 10 < abs(reversed))
        {
            reversed = 0;
            break;
        }

        reversed = (reversed*10) + (absX % 10);
        absX /= 10;
    }

    return x < 0 ? -1*reversed : reversed;       
}

/*
int numDigits = x == INT_MIN ? 9 : floor(log10(abs(x)));
    int iMax = x > 0 ? INT_MAX : INT_MIN;

    int reversed = 0;
    for(int i = numDigits; i >= 0; --i)
    {
        int digit = x < 0 ? ceil(x / pow(10,i)) : floor(x / pow(10, i));
        if(numDigits == 9)
        {
            if((x > 0 && digit > (iMax % 10)) || (x < 0 && digit < (iMax % 10)))
                return 0;
            iMax /= 10;
        }

        reversed += pow(10, numDigits-i) * digit;
        x %= (int)pow(10,i);
    }

    return reversed;  
*/