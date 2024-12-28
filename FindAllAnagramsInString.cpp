
#include<bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p);
bool checkMatch(int* window, int* pattern);

int main()
{
    string s = "abab";
    string p = "ab";
    
    findAnagrams(s,p);

    getchar();
    return 0;
}

vector<int> findAnagrams(string s, string p) 
{
    vector<int> anagramPos;

    int pChars[26] = {0};
    for(int i = 0; i < p.size(); ++i)
    {
        pChars[p[i] - 'a']++;
    }

    int l = 0;
    int r = 0;
    int* windowChars = new int[26]();
    while(r < s.size())
    {
        windowChars[s[r] - 'a']++;
        
        while(l <= r && windowChars[s[r] - 'a'] > pChars[s[r] - 'a'])
        {
            windowChars[s[l] - 'a']--;
            l++;
        }

        if(checkMatch(windowChars, pChars))
            anagramPos.push_back(l);

        r++;
    }

    return anagramPos;        
}

bool checkMatch(int* window, int* pattern)
{
    for(int i = 0; i < 26; ++i)
    {
        if(window[i] != pattern[i])
            return false;
    }

    return true;
}