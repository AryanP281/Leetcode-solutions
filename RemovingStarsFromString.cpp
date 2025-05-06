
#include<bits/stdc++.h>

using namespace std;

string removeStars(string s);

int main()
{

    cout << removeStars("leet**cod*e");

    getchar();
    return 0;
}

string removeStars(string s) 
{
    string resultString = "";
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '*')
            resultString.pop_back();
        else
            resultString.push_back(s[i]);
    }

    return resultString;
}