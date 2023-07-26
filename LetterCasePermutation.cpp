
#include<bits/stdc++.h>

using namespace std;

vector<string> letterCasePermutation(string& S);
void generateStrings(string& str, int pos, vector<string>& strs);

int main()
{
    string str = "0";
    vector<string> strs = letterCasePermutation(str);

    for(int a = 0; a < strs.size(); ++a)
    {
        cout << strs[a] << ' ';
    }

    getchar();
    return 0;
}

vector<string> letterCasePermutation(string& S) 
{
    vector<string> strs;
    strs.reserve(pow(2,S.size()));

    generateStrings(S, 0, strs);

    return strs;
}

void generateStrings(string& str, int pos, vector<string>& strs)
{
    if(pos == str.size())
    {
        strs.push_back(str);
        return;
    }

    if(isalpha(str[pos]))
    {
        char originalChar = str[pos];
        
        str[pos] = tolower(originalChar);
        generateStrings(str, pos+1, strs);

        str[pos] = toupper(originalChar);
        generateStrings(str, pos+1, strs);

        str[pos] = originalChar;
    }
    else
        generateStrings(str,pos+1,strs);
    
}