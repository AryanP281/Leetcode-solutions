
#include<bits/stdc++.h>

using namespace std;

bool wordBreak(string& s, vector<string>& wordDict);
bool canBreak(string& s, unordered_set<string>& dict, int l, int* lookupTable);

int main()
{
    string str = "aaaaaaa";
    vector<string> dict = {"aaaa", "aaa"};
    cout << wordBreak(str, dict);

    getchar();
    return 0;
}

bool wordBreak(string& s, vector<string>& wordDict) 
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int* lookupTable = new int[s.size()];
    fill_n(lookupTable, s.size(), -1);

    bool res = canBreak(s, dict, 0, lookupTable);
    delete[] lookupTable;

    return res;
}

bool canBreak(string& s, unordered_set<string>& dict, int l, int* lookupTable)
{
    /*Checking if prefix of substring exists in word dictionary. Requires only one loop as if prefix was valid 
    it would have already been checked. For eg, consider s="catsandog", l=3, dict={"cats","dog","sand","and","cat"},
    no point in considering all substrings starting from a=4 as we can say that the substring from [3,4) i.e 's' is 
    invalid, since if it would have been valid it would have already been considered during substrings stating from a=3 as 's' and 
    'andog'*/
    
    if(l >= s.size()) return true;
    if(lookupTable[l] != -1) return lookupTable[l];

    lookupTable[l] = 0;
    string substr = "";
    for(int a = l; a < s.size(); ++a)
    {
        substr += s[a];
        if(dict.find(substr) != dict.end() && canBreak(s, dict, a+1, lookupTable))
        {
            lookupTable[l] = 1;
            break;
        }
    }

    return lookupTable[l];
}

/*
bool wordBreak(string& s, vector<string>& wordDict) 
{
    int** lookupTable = new int*[s.size()];
    for(int a = 0; a < s.size(); ++a)
    {
        lookupTable[a] = new int[s.size()]();
        fill_n(lookupTable[a], s.size(), -1);
    }
    
    vector<vector<int>> substringOccrs;
    for(int a = 0; a < wordDict.size(); ++a)
    {
        substringOccrs.push_back(vector<int>());
        getSubstringOccrs(s, wordDict[a], *substringOccrs.rbegin());
        for(int b = 0; b < substringOccrs.rbegin()->size(); ++b)
        {
            int l = substringOccrs.rbegin()->at(b);
            lookupTable[l][l+wordDict[a].size()-1] = 1;
        }
    }

    return checkInterval(wordDict,substringOccrs,0,s.size()-1,lookupTable);
}

bool checkInterval(vector<string>& words, vector<vector<int>>& substrLocs, int l, int r, int** lookupTable)
{
    if(l > r) return true;
    else if(lookupTable[l][r] != -1) return lookupTable[l][r];
    
    lookupTable[l][r] = 0;
    for(int a = 0; a < substrLocs.size(); ++a)
    {
        for(int b = 0; b < substrLocs[a].size(); ++b)
        {
            if(substrLocs[a][b] >= l && (substrLocs[a][b]+words[a].size()-1) <= r)
            {
                if(checkInterval(words, substrLocs, l, substrLocs[a][b]-1,lookupTable) && 
                    checkInterval(words, substrLocs, substrLocs[a][b]+words[a].size(), r,lookupTable))
                    {
                        lookupTable[l][r] = 1;
                        return true;
                    }
                
            }
        }
    }

    return lookupTable[l][r];
}

void getSubstringOccrs(string& str, string& subStr, vector<int>& occrs)
{
    if(str.size() < subStr.size()) return;
    
    auto substrEquals = [str,subStr](int l, int r) -> bool
    {
        for(int a = l; a <= r; ++a)
        {
            if(str[a] != subStr[a-l]) return false;
        }
        return true;
    };

    for(int a = 0; a <= str.size() - subStr.size(); ++a)
    {
        if(substrEquals(a, a+subStr.size()-1)) occrs.push_back(a);
    }
}


void getSubstringOccrs(string& str, string& subStr, vector<int>& occrs)
{
    int substrChars[26][2] = {{0,0}};
    for(int a = 0; a < subStr.size(); ++a)
    {
        substrChars[subStr[a] - 'a']++;
    }
    
    int chars[26] = {0};
    for(int a = 0; a < subStr.size(); ++a)
    {
        chars[str[a] - 'a']++;
    }
    if(containsStr(substrChars, chars)) occrs.push_back(0);

    for(int a = subStr.size(); a < str.size(); ++a)
    {
        chars[str[a-subStr.size()] - 'a']--;
        chars[str[a] - 'a']++;
        if(containsStr(substrChars, chars)) occrs.push_back(a-subStr.size()+1);
    }

}

bool containsStr(int* strChars, int* winChars)
{
    for(int a = 0; a < 26; ++a)
    {
        if(strChars[a] != winChars[a]) return false;
    }

    return true;
}

vector<int> getSubstringOccrs(string& str, string& subStr)
{
    vector<int> occrs;
    int i = 0;
    for(int a = 0; a < str.size(); ++a)
    {
        if(str[a] == subStr[i])
        {
            if(i != subStr.size() - 1) ++i;
            else
            {
                occrs.push_back(a - i);
                i = 0;
            }
            
        }
        else i = 0;
    }


    return occrs;
}*/