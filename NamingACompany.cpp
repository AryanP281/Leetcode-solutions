
#include<bits/stdc++.h>

using namespace std;

long long distinctNames(vector<string>& ideas);
uint64_t encode(string& str);

int main()
{
    vector<string> ideas = {"aaa","baa","caa","bbb","cbb","dbb"};
    cout << distinctNames(ideas);

    getchar();
    return 0;
}

long long distinctNames(vector<string>& ideas) 
{
    unordered_map<uint64_t,unordered_set<char>> groups;
    unordered_set<char> starts;
    for(int i = 0; i < ideas.size(); ++i)
    {
        uint64_t encd = encode(ideas[i]);
        unordered_map<uint64_t,unordered_set<char>>::iterator itr = groups.find(encd);
        if(itr == groups.end())
            groups[encd] = {ideas[i][0]};
        else
            itr->second.insert(ideas[i][0]);
        starts.insert(ideas[i][0]);
    }   
    
    long long alphPairCounts[26][26] = {{0}};
    for(auto itr1 = starts.begin(); itr1 != starts.end(); ++itr1)
    {
        for(auto itr2 = starts.begin(); itr2 != starts.end(); ++itr2)
        {
            for(auto grp = groups.begin(); grp != groups.end(); ++grp)
            {
                if(grp->second.count(*itr1) && !grp->second.count(*itr2))
                    alphPairCounts[*itr1 - 'a'][*itr2 - 'a'] += 1;
            }
        }
    }

    long long nameCounts = 0;
    for(auto grp = groups.begin(); grp != groups.end(); ++grp)
    {
        for(auto start = grp->second.begin(); start != grp->second.end(); ++start)
        {
            for(auto itr = starts.begin(); itr != starts.end(); ++itr)
            {
                if(grp->second.count(*itr) == 0)
                    nameCounts += alphPairCounts[*itr - 'a'][*start - 'a'];
            }
        }
    }
    
    return nameCounts;
}

uint64_t encode(string& str)
{
    uint64_t encoding = 0;
    for(int i = 1; i < str.size(); ++i)
    {
        encoding |= (uint64_t)(str[i] - 'a') << (i*5);
    }

    return encoding;
}