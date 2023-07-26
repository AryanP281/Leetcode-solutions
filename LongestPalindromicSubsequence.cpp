
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int longestPalindromeSubseq(string s);
int getLongest(string& str, int l, int r, int** lookupTable);

int main()
{
    string str = "acbea";
    cout << longestPalindromeSubseq(str);

    getchar();
    return 0;
}

int longestPalindromeSubseq(string s) 
{
    int** lookupTable = new int*[s.size()];
    for(int a = 0; a < s.size(); ++a)
    {
        lookupTable[a] = new int[s.size()];
        fill_n(lookupTable[a],s.size(),-1);
    }

    int longestSubsequence = getLongest(s, 0, s.size()-1, lookupTable);  

    for(int a = 0; a < s.size(); ++a)
    {
        delete[] lookupTable[a];
    }
    delete[] lookupTable;

    return longestSubsequence;
}

int getLongest(string& str, int l, int r, int** lookupTable)
{
    if(l > r)
        return 0;

    if(lookupTable[l][r] != -1)
        return lookupTable[l][r];    

    unordered_map<char,Vec> charMaxRanges;
    unordered_map<char,Vec>::iterator itr;
    for(int i = l; i <= r; ++i)
    {
        itr = charMaxRanges.find(str[i]);
        if(itr == charMaxRanges.end())
            charMaxRanges[str[i]] = Vec(i,-1);
        else
            itr->second.second = i;
    }

    int newSubsequenceLength;
    lookupTable[l][r] = 1;
    for(itr = charMaxRanges.begin(); itr != charMaxRanges.end(); ++itr)
    {
        if(itr->second.second == -1)
            continue;

        newSubsequenceLength = 2 + getLongest(str, itr->second.first+1, itr->second.second-1, lookupTable);
        if(newSubsequenceLength > lookupTable[l][r])
            lookupTable[l][r] = newSubsequenceLength;
    }

    return lookupTable[l][r];
}