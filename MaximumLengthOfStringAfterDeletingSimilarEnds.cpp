
#include<bits/stdc++.h>

using namespace std;

int minimumLength(string s);

int main()
{
    cout << minimumLength("bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb");

    getchar();
    return 0;
}

int minimumLength(string s) 
{
    int l1 = 0;
    int l2;
    int r1 = s.size()-1;
    int r2;
    
    while(l1 < r1 && s[l1] == s[r1])
    {
        l2 = l1+1;
        while(l2 < r1 && s[l2] == s[l1])
        {
            l2++;
        }

        r2 = r1-1;
        while(r2 > l2 && s[r2] == s[r1])
        {
            r2--;
        }

        l1 = l2;
        r1 = r2;
    }

    return r1-l1+1;
}