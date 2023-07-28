
#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
    string s = "123abcdef21hghk";
    cout << lengthOfLongestSubstring(s);

    getchar();
    return 0;
}

int lengthOfLongestSubstring(string s) 
{
    unordered_map<char,int> charPos;
    unordered_map<char,int>::iterator itr;

    int maxLen = 0;
    int l = 0;

    charPos.insert(pair<char,int>(s[0], 0));
    for(int r = 1; r < s.size(); ++r)
    {
        itr = charPos.find(s[r]);
        if(itr != charPos.end() && itr->second >= l)
        {
            maxLen = max(maxLen,r-l);
            l = itr->second + 1;
            itr->second = r;
        }
        else
            charPos.operator[](s[r]) = r;
    }
    maxLen = max(maxLen, (int)s.size()-l);

    return maxLen;
}