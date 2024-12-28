
#include<bits/stdc++.h>

using namespace std;

int main()
{


    getchar();
    return 0;
}

int minSwaps(string s) 
{
    int currExtra = 0;
    int maxExtra = 0;

    for(int i = 0; i < s.size(); ++i)
    {
        switch(s[i])
        {
            case ']': currExtra += 1; break;
            case '[': currExtra -= 1; break;
        }
        maxExtra = max(currExtra, maxExtra);
    }

    return (int)ceil((double)maxExtra/2.0);
}