
#include<bits/stdc++.h>

using namespace std;

string minWindow(string s, string t);
void setBit(int64_t* mask, char ch);
void unsetBit(int64_t* mask, char ch);

int main()
{
    string s = "caccaacaaaabbcaccaccc";
    string t = "acccacbccc";

    cout << minWindow(s, t);

    getchar();
    return 0;
}

string minWindow(string s, string t) 
{
    if(s.size() < t.size())
        return "";
    
    unordered_map<char,int> tCharFreqs;
    int64_t charMask = 0;
    for(int i = 0; i < t.size(); ++i)
    {
        tCharFreqs[t[i]]++;
        setBit(&charMask, t[i]);
    }

    int l = 0;
    int r = 0;
    int minSubstring[3] = {(int)s.size()+1,-1,-1};
    unordered_map<char,int> windowCharFreqs;
    unordered_map<char,int>::iterator itr;
    for(; r < s.size(); ++r)
    {
        itr = tCharFreqs.find(s[r]);
        if(itr == tCharFreqs.end())
            continue;
        
        windowCharFreqs[s[r]]++;
        if(windowCharFreqs[s[r]] == itr->second)
        {
            unsetBit(&charMask, s[r]);
        }
        
        if(windowCharFreqs[s[r]] > itr->second || charMask == 0)
        {
            bool shortenWindow = true;
            while(shortenWindow)
            {
                itr = tCharFreqs.find(s[l]);
                if(itr != tCharFreqs.end())
                {
                    if(windowCharFreqs[s[l]] > itr->second)
                        windowCharFreqs[s[l]]--;
                    else
                    {
                        l--;
                        shortenWindow = false;
                    }

                }
                l++;
            }

            if(charMask == 0)
            {
                if(r-l+1 < minSubstring[0])
                {
                    minSubstring[0] = r-l+1;
                    minSubstring[1] = l;
                    minSubstring[2] = r;
                }
            }
        }
    }

    if(minSubstring[1] == -1)
        return "";
    
    return s.substr(minSubstring[1], minSubstring[0]);
}

void setBit(int64_t* mask, char ch)
{
    if(ch >= 'a')
        *mask |= (1 << (26 + (int)(ch - 'a')));
    else
        *mask |= (1 << (int)(ch - 'A'));
}

void unsetBit(int64_t* mask, char ch)
{
    if(ch >= 'a')
        *mask &= ~(1 << (26 + (int)(ch - 'a')));
    else
        *mask &= ~(1 << (int)(ch - 'A'));
}