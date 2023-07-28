
#include<bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2);

int main()
{
    string s1 = "abc";
    string s2 = "bbbca";

    cout << (checkInclusion(s1,s2) ? "True" : "False");

    getchar();
    return 0;
}

bool checkInclusion(string s1, string s2) 
{    
    if(s2.size() < s1.size())
        return false;

    int* s1CharCounts = new int['z' - 'a' + 1]();
    for(int i = 0; i < s1.size(); ++i)
    {
        s1CharCounts[s1[i] - (int)'a']++;
    }

    int r = 0;
    int* windowCharCounts = new int['z' - 'a' + 1]();
    for(; r < s1.size(); ++r)
    {
        windowCharCounts[s2[r] - (int)'a']++;
    }

    int32_t s1Signature = 0;
    for(int i = 0; i <= 'z' - 'a'; ++i)
    {
        if(windowCharCounts[i] != s1CharCounts[i])
            s1Signature |= (1 << i);
    }

    int l=1;
    for(; r < s2.size() && s1Signature; ++r,++l)
    {
        windowCharCounts[s2[l-1] - (int)'a']--;
        if(windowCharCounts[s2[l-1] - (int)'a'] == s1CharCounts[s2[l-1] - (int)'a'])
            s1Signature &= ~(1 << (s2[l-1] - (int)'a'));
        else
            s1Signature |= (1 << (s2[l-1] - (int)'a'));
        
        windowCharCounts[s2[r] - (int)'a']++;
        if(windowCharCounts[s2[r] - (int)'a'] == s1CharCounts[s2[r] - (int)'a'])
            s1Signature &= ~(1 << (s2[r] - (int)'a'));
        else
            s1Signature |= (1 << (s2[r] - (int)'a'));
    }

    delete[] s1CharCounts;
    delete[] windowCharCounts;

    return (s1Signature == 0);   
}