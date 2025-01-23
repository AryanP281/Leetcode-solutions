
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

int partitionString(string s) 
{
    unordered_set<char> currWindow;
    int partitionCount = 0;

    for(int i = 0; i < s.size(); ++i)
    {
        if(currWindow.count(s[i]))
        {
            partitionCount++;
            currWindow.clear();
        }
        currWindow.insert(s[i]);
    }

    return ++partitionCount;        
}