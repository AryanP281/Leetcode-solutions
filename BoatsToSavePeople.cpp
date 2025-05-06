
#include<bits/stdc++.h>

using namespace std;

int numRescueBoats(vector<int>& people, int limit);

int main()
{

    vector<int> people = {2,2};
    cout << numRescueBoats(people, 6);

    getchar();
    return 0;
}

int numRescueBoats(vector<int>& people, int limit) 
{
    map<int,int> elems;
    for(int i = 0; i < people.size(); ++i)
    {
        elems[people[i]]++;
    }

    int boatsCount = 0;
    while(!elems.empty())
    {
        int curr = elems.rbegin()->first;
        elems.rbegin()->second--;
        if(elems.rbegin()->second == 0)
            elems.erase(prev(elems.end()));

        int pair = limit - curr;
        map<int,int>::iterator lb = elems.lower_bound(pair);
        if(elems.size())
        {
            if((lb == elems.end() || lb->first != pair) && lb != elems.begin())
                lb = prev(lb);

            if(lb->first <= pair)
            {
                if(lb->second == 1)
                    elems.erase(lb);
                else
                    lb->second--;
            }  
        }
      

        boatsCount++;
    }

    return boatsCount;
}