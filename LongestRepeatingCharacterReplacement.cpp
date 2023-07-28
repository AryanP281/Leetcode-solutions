
#include<bits/stdc++.h>

using namespace std;

int characterReplacement(string s, int k);

int main()
{
    string s = "AAAB";
    cout << characterReplacement(s, 0);

    getchar();
    return 0;
}

int characterReplacement(string s, int k) 
{
    unordered_map<char,int> charStartPos;
    for(int i = 0; i < s.size(); ++i)
    {
        charStartPos.insert(pair<char,int>(s[i],i));
    }

    int l,r;
    int maxSize = 1*(charStartPos.size() > 0);
    for(unordered_map<char,int>::iterator ch = charStartPos.begin(); ch != charStartPos.end(); ++ch)
    {
        deque<int> replacedPos;
        for(l = ch->second - 1; l >= 0 && replacedPos.size() < k; --l)
        {
            replacedPos.push_front(l);
        }

        for(int r = ch->second; r < s.size(); ++r)
        {
            if(s[r] == ch->first)
                continue;

            if(replacedPos.size() == k)
            {
                maxSize = max(maxSize, r-l-1);
                if(!replacedPos.empty())
                {
                    l = replacedPos.front();
                    replacedPos.pop_front();
                }
                else
                    l = r;
            }
            replacedPos.push_back(r);
        }
        maxSize = max(maxSize, (int)s.size()-l-1);
    }

    return maxSize;
}

