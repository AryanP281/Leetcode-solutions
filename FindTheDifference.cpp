
#include<bits/stdc++.h>

using namespace std;

char findTheDifference(string s, string t);

int main()
{
    cout << findTheDifference("ae", "aea");

    getchar();
    return 0;
}

char findTheDifference(string s, string t) 
{
    int sXor = 0;
    for(int a = 0; a < s.size(); ++a)
    {
        sXor ^= s[a];
    }

    for(int a = 0; a < t.size(); ++a)
    {
        sXor ^= t[a];
    }

    return sXor;   
}