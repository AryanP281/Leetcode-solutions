
#include<bits/stdc++.h>

using namespace std;

bool checkIfCanBreak(string s1, string s2);

int main()
{
    cout << checkIfCanBreak("leetcodee", "interview");
    
    getchar();
    return 0;
}

bool checkIfCanBreak(string s1, string s2) 
{
    int s1Chars[26] = {0};
    int s2Chars[26] = {0};

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int a = 0; a < s1.size(); ++a)
    {
        s1Chars[s1[a]-'a']++;
    }

    for(int a = 0; a < s2.size(); ++a)
    {
        s2Chars[s2[a] - 'a']++;
    }

    bool breakable = true;
    for(int a = s1.size()-1; a >= 0; --a)
    {
        int b = s1[a] - 'a';
        for(; b < 26; ++b)
        {
            if(s2Chars[b] > 0)
            {
                s2Chars[b]--;
                break;
            }
        }

        if(b == 26)
        {
            breakable = false;
            break;
        }
    }

    if(breakable) return true;

    breakable = true;
    for(int a = s2.size()-1; a >= 0; --a)
    {
        int b = s2[a] - 'a';
        for(; b < 26; ++b)
        {
            if(s1Chars[b] > 0)
            {
                s1Chars[b]--;
                break;
            }
        }

        if(b == 26)
        {
            breakable = false;
            break;
        }
    }

    return breakable;
}