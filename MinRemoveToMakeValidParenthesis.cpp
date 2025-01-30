
#include<bits/stdc++.h>

using namespace std;

string minRemoveToMakeValid(string s);

int main()
{
    string s = "a)b(c)d";
    cout << minRemoveToMakeValid(s);

    getchar();

    return 0;
}

string minRemoveToMakeValid(string s) 
{
    stack<int> openBraces;
    unordered_set<int> toRemove;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '(')
            openBraces.push(i);
        else if(s[i] == ')')
        {
            if(openBraces.empty())
                toRemove.insert(i);
            else
                openBraces.pop();
        }
    }

    while(!openBraces.empty())
    {
        toRemove.insert(openBraces.top());
        openBraces.pop();
    }

    string result = "";
    for(int i = 0; i < s.size(); ++i)
    {
        if(toRemove.count(i))
            continue;
        result += s[i];
    }

    return result;    
}