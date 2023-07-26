
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
    char currChar = s[0];

    int l = 0;
    int r = s.size()-1;
    int ends[2] = {0,(int)s.size()-1};
    int minLen = s.size();
    while(l < r && s[ends[0]] == s[ends[1]])
    {
        while(s[l] == s[ends[0]] && l < s.size())
        {
            l++;
        }

        while(r >= l && s[r] == s[ends[1]])
        {
            r--;
        }

        minLen -= (l - ends[0]) + (ends[1] - r);
        ends[0] = l;
        ends[1] = r;
    }
    

    return minLen;   
}