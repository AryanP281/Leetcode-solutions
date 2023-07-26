
#include<bits/stdc++.h>

using namespace std;

string customSortString(string S, string T);

int main()
{
    string s = "cba";
    string t = "abcd";

    cout << customSortString(s,t); 

    getchar();
    return 0;
}

string customSortString(string S, string T) 
{
    unordered_map<char,int> charOrders;
    for(int a = 0; a < S.size(); ++a)
    {
        charOrders[S[a]] = a;
    }

    auto cmp = [&charOrders](char i, char j) -> bool
    {
        unordered_map<char,int>::iterator itr = charOrders.find(i);
        if(itr == charOrders.end())
            return false;
        
        int order = itr->second;
        itr = charOrders.find(j);

        return (itr == charOrders.end() || order < itr->second);
    };

    sort(T.begin(), T.end(), cmp);

    return T;
}