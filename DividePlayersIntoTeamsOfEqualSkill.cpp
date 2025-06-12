
#include<bits/stdc++.h>

using namespace std;

long long dividePlayers(vector<int>& skill);

int main()
{

    vector<int> skill = {3,2,5,1,3,4};
    cout << dividePlayers(skill);

    getchar();

    return 0;
}

long long dividePlayers(vector<int>& skill) 
{
    typedef long long ll;

    ll groupCount = skill.size() / 2; 
    ll skillSum = accumulate(skill.begin(), skill.end(), 0);
    
    if(skillSum % groupCount)
        return -1;

    unordered_map<int,int> elements;
    for(int i = 0; i < skill.size(); ++i)
    {
        elements[skill[i]]++;
    }
    
    ll groupSkill = skillSum / groupCount;
    ll chemstry = 0;
    while(!elements.empty())
    {
        while(elements.size() && elements.begin()->second == 0)
            elements.erase(elements.begin());
        
        if(!elements.empty())
        {
            ll currSkill = elements.begin()->first;
            elements[elements.begin()->first] = elements.begin()->second-1;

            unordered_map<int,int>::iterator itr = elements.find(groupSkill-elements.begin()->first);
            if(itr != elements.end() && itr->second > 0)
            {
                chemstry += currSkill * itr->first;
                elements[itr->first] = itr->second-1;
            }
            else
                return -1;
        }
    }

    return chemstry;
}