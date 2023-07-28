
#include<bits/stdc++.h>

using namespace std;

typedef pair<string,int> Vec;

vector<vector<string>> groupAnagrams(vector<string>& strs);

int main()
{
    vector<string> strs = {""};
    vector<vector<string>> groups = groupAnagrams(strs);

    getchar();
    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<Vec> strCpy;
    for(int i = 0; i < strs.size(); ++i)
    {
        strCpy.push_back(Vec(strs[i],i));
        sort(strCpy[i].first.begin(),strCpy[i].first.end());
    }

    auto comparator = [](Vec& v1, Vec& v2) -> bool {
        return v1.first < v2.first;
    };
    sort(strCpy.begin(), strCpy.end(), comparator);

    vector<vector<string>> groups;
    int j;
    for(int i = 0; i < strCpy.size(); i=j)
    {
        j = i;
        groups.push_back(vector<string>());
        while(j < strCpy.size() && strCpy[j].first == strCpy[i].first)
        {
            groups.rbegin()->push_back(strs[strCpy[j++].second]);
        }
    }

    return groups;
}   