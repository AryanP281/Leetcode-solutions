
#include<bits/stdc++.h>

using namespace std;

int main()
{


    getchar();

    return 0;
}

string minWindow(string s, string t) 
{
    if(s.size() < t.size())
        return "";
        
    unordered_map<char,int> tCharFreqs;
    for(char ch : t)
    {
        tCharFreqs[ch]++;
    }

    unordered_map<char,int> windowFreqs;
    int currUnmatched = tCharFreqs.size();
    unordered_map<char,int>::iterator itr;
    int minWindow[2] = {-1,(int)s.size()+1};
    int l = 0;
    for(int r = 0; r < s.size(); ++r)
    {
        windowFreqs[s[r]]++;
        itr = tCharFreqs.find(s[r]);
        if(itr != tCharFreqs.end() && itr->second == windowFreqs[s[r]])
            currUnmatched--;

        while(currUnmatched == 0)
        {
            if(r-l+1 < minWindow[1])
            {
                minWindow[0] = l;
                minWindow[1] = r-l+1;
            }

            windowFreqs[s[l]]--;
            itr = tCharFreqs.find(s[l]);
            if(itr != tCharFreqs.end() && windowFreqs[s[l]] < itr->second)
                currUnmatched = 1;
            l++;
        }
    }

    if(minWindow[0] == -1)
        return "";

    return s.substr(minWindow[0], minWindow[1]);
}
