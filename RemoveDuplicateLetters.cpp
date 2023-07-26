
#include<bits/stdc++.h>

using namespace std;

string removeDuplicateLetters(string s);

int main()
{
    cout << removeDuplicateLetters("bbcaac");

    getchar();
    return 0;
}

string removeDuplicateLetters(string s) 
{
    int lastPos[26] = {-1};
    for(int i = 0; i < s.size(); ++i)
    {
        lastPos[s[i] - 'a'] = i;
    }

    stack<int> subsequence;
    bool addedToSubsequence[26] = {false};
    for(int i = 0; i < s.size(); ++i)
    {
        if(!addedToSubsequence[s[i] - 'a'])
        {
            while(!subsequence.empty() && s[subsequence.top()] >= s[i] && lastPos[s[subsequence.top()] - 'a'] > i)
            {
                addedToSubsequence[s[subsequence.top()] - 'a'] = false;
                subsequence.pop();
            }

            subsequence.push(i);
            addedToSubsequence[s[i]-'a'] = true;
        }
    }

    string newString = "";
    while(!subsequence.empty())
    {
        newString += s[subsequence.top()];
        subsequence.pop();
    }
    reverse(newString.begin(), newString.end());

    return newString;
}