
#include<bits/stdc++.h>

using namespace std;

long long numberOfWays(string s);

int main()
{
    string s = "0001100100";
    cout << numberOfWays(s);

    getchar();
    return 0;
}

long long numberOfWays(string s) 
{
    //currLevel[i][s[i]] = currLevel[i-1][s[i]] + prevLevel[i][(s[i]+1) % 2]
    //currLevel[i][(s[i]+1)%2] = currLevel[i-1][(s[i]+1)%2]   
    
    vector<long long>* prevLevel = new vector<long long>[s.size()];
    for(int i = 0; i < s.size(); ++i)
    {
        prevLevel[i] = {0,0};
        prevLevel[i][s[i]-'0'] = prevLevel[max(0,i-1)][s[i] - '0'] + 1;
        prevLevel[i][(s[i]-'0'+1) % 2] = prevLevel[max(0,i-1)][(s[i]-'0'+1) % 2];
    }

    vector<long long>* currLevel = new vector<long long>[s.size()];
    for(int level = 2; level <= 3; ++level)
    {
        for(int i = 0; i < s.size(); ++i)
        {   
            currLevel[i] = {0,0};
            if(i < level - 1)
                continue;
            
            currLevel[i][s[i] - '0'] = currLevel[i-1][s[i] - '0'] + prevLevel[i][(s[i] - '0' + 1) % 2];
            currLevel[i][(s[i] - '0' + 1) % 2] = currLevel[i-1][(s[i] - '0' + 1) % 2];
        }

        delete[] prevLevel;
        prevLevel = currLevel;
        currLevel = new vector<long long>[s.size()];
    }
    
    long long waysCount = prevLevel[s.size()-1][0] + prevLevel[s.size()-1][1];

    delete[] prevLevel;
    delete[] currLevel;

    return waysCount;
}