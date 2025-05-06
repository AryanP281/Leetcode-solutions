
#include<bits/stdc++.h>

using namespace std;

int minFlips(string s);

int main()
{

    cout << minFlips("10001100101000000");

    getchar();

    return 0;
}

int minFlips(string s) 
{
    int oddParity = 0;
    int evenParity = 0;
    int oddCount = ceil((double)s.size()/2.0);
    int evenCount = floor((double)s.size()/2.0);

    for(int i = 0; i < s.size(); ++i)
    {
        if((i+1) % 2)
            oddParity += s[i] - '0';
        else
            evenParity += s[i] - '0';
    }

    int result = min(oddCount - oddParity + evenParity, evenCount - evenParity + oddParity);
    bool isOddLength = ((s.size() % 2) != 0);
    for(int i = 0; i < s.size();++i)
    {
        if(isOddLength)
        {
            int temp = evenParity;
            evenParity = oddParity - (s[i] - '0');
            oddParity = temp + (s[i] - '0');
        }
        else
        {
            int temp = evenParity;
            evenParity = oddParity;
            oddParity = evenParity;
        }

        result = min(result,min(oddCount - oddParity + evenParity, evenCount - evenParity + oddParity));
    }

    return result;
}

