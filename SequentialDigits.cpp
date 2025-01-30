
#include<bits/stdc++.h>

using namespace std;

vector<int> sequentialDigits(int low, int high);

int main()
{
    sequentialDigits(1000,13000);

    getchar();

    return 0;
}

vector<int> sequentialDigits(int low, int high) 
{
    int currPow = floor(log10(low));
    int currDigit = floor((double)low / pow(10,currPow));
    vector<int> result;
    while(true)
    {
        int currNum = currDigit * pow(10, currPow);
        int prevDigit = currDigit;
        for(int i = currPow-1; i >= 0; --i)
        {
            if(prevDigit == 9)
            {
                prevDigit = -1;
                break;
            }

            currNum += (++prevDigit)*pow(10,i);
        }

        if(prevDigit != -1 && currNum <= high && currNum >= low)
            result.push_back(currNum);
        else if(currNum > high)
            break;

        if(currDigit == 9)
        {
            currDigit = 1;
            currPow++;
        }
        else
            currDigit++;
    }

    return result;        
}