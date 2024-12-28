
#include<bits/stdc++.h>

using namespace std;

bool isIsomorphic(string s, string t);

int main()
{

    string s = "foo";
    string t = "bar";

    cout << isIsomorphic(s,t);

    getchar();
    return 0;
}

bool isIsomorphic(string s, string t) 
{
    char** charMaps = new char*[2];
    charMaps[0] = new char[128];
    charMaps[1] = new char[128];
    fill_n(&charMaps[0][0], 128, -1);
    fill_n(&charMaps[1][0], 128, -1);
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(charMaps[0][s[i]] != -1 && t[i] != charMaps[0][s[i]])
            return false;
        else if(charMaps[0][s[i]] == -1)
        {
            if(charMaps[1][t[i]] != -1)
                return false;
            charMaps[0][s[i]] = t[i];
            charMaps[1][t[i]] = s[i];
        }
    }


    delete[] charMaps[0];
    delete[] charMaps[1];
    delete[] charMaps;

    return true;
}