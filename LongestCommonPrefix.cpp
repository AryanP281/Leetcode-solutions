
#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main()
{
    vector<string> strs = {"dog","racecar","car"};
    cout << longestCommonPrefix(strs);
    
    getchar();
    return 0;
}

string longestCommonPrefix(vector<string>& strs) 
{
    if(strs.size() == 0)
        return "";
    
    string* minSizeStr = &strs[0];
    for(int a = 1; a < strs.size(); ++a)
    {
        if(strs[a].size() < minSizeStr->size())
            minSizeStr = &strs[a];
    }

    int i = 0;
    bool prefixFound = false;
    for(; i < minSizeStr->size() && !prefixFound; i += !prefixFound)
    {
        for(int j = 0; j < strs.size(); ++j)
        {
            if((*minSizeStr)[i] != strs[j][i])
            {
                prefixFound = true;
                break;
            }
        }
    }

    return (i == 0) ? "" : minSizeStr->substr(0, i);   
}