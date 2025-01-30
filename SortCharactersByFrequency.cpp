
#include<bits/stdc++.h>

using namespace std;

string frequencySort(string s);

int main()
{
    string s = "tree";
    cout << frequencySort(s);

    getchar();
    return 0;
}

string frequencySort(string s) 
{
    //Bucket sort

    unordered_map<char,int> freqs;
    for(int i = 0; i < s.size(); ++i)
    {
        freqs[s[i]]++;
    }

    queue<char>* buckets = new queue<char>[s.size()+1];
    for(unordered_map<char,int>::iterator itr = freqs.begin(); itr != freqs.end(); itr++)
    {
        buckets[itr->second].push(itr->first);
    }

    string sortedString = "";
    for(int i = s.size(); i > 0; i--)
    {
        while(!buckets[i].empty())
        {
            for(int j = 0; j < i; ++j)
            {
                sortedString += buckets[i].front();
            }
            buckets[i].pop();
        }
    }

    delete[] buckets;

    return sortedString;
}