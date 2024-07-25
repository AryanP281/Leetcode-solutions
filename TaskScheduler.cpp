#include<bits/stdc++.h>

using namespace std;

int leastInterval(vector<char>& tasks, int n);

int main()
{

    vector<char> tasks = {'A','A','A','B','B','B'};
    cout << leastInterval(tasks, 2);

    getchar();
    return 0;
}

int leastInterval(vector<char>& tasks, int n) 
{
    typedef pair<char,int> Vec;
    
    multimap<int,Vec,greater<int>> freqMap;
    int freqs[26] = {0};
    for(int i = 0; i < tasks.size(); ++i)
    {
        freqs[tasks[i] - 'A']++;
    }
    for(int i = 0; i < 26; ++i)
    {
        if(freqs[i] != 0)
        {
            freqMap.insert(pair<int,Vec>(freqs[i], Vec('A'+i,-n-1)));
        }
    }

    int intervalSize = 0;
    while(!freqMap.empty())
    {
        for(multimap<int,Vec>::iterator itr = freqMap.begin(); itr != freqMap.end(); ++itr)
        {
            if(intervalSize - itr->second.second > n)
            {
                if(itr->first > 1)
                {
                    pair<int,Vec> ue(itr->first-1, Vec(itr->second.first, intervalSize));
                    freqMap.insert(ue);
                }
                freqMap.erase(itr);
                break;
            }
        }

        intervalSize++;
    }

    return intervalSize;
}