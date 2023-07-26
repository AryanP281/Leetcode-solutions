
#include<bits/stdc++.h>

using namespace std;

int numRescueBoats(vector<int>& people, int limit);

int main()
{
    vector<int> people = {3,5,3,4};
    int limit = 5;
    cout << numRescueBoats(people, limit);

    getchar();
    return 0;
}

int numRescueBoats(vector<int>& people, int limit)
{
    sort(people.begin(), people.end());

    int l = 0;
    int r = people.size()-1;
    int boats = 0;

    while(l <= r)
    {
        if((limit - people[r]) >= people[l])
        {
            ++l;
            --r;
        }
        else
            --r;
        
        ++boats;
    }

    return boats;
}

/*int numRescueBoats(vector<int>& people, int limit) 
{
    map<int,int> peopleLeft;
    for(int a = 0; a < people.size(); ++a)
    {
        peopleLeft[people[a]]++;
    }

    int boats = 0;
    int currCapacity;
    for(map<int,int>::iterator itr = peopleLeft.begin(); itr != peopleLeft.end();)
    {
        currCapacity = limit - itr->first;
        if(itr->second == 1)
        { 
            map<int,int>::iterator temp = itr;
            ++itr;
            peopleLeft.erase(temp);
        }
        else
            itr->second--;
        
        if(!peopleLeft.empty() && peopleLeft.begin()->first <= currCapacity)
        {
            map<int,int>::iterator otherItr = peopleLeft.lower_bound(currCapacity);
            if(otherItr->first != currCapacity) otherItr--;

            if(otherItr->second == 1)
            {
                if(otherItr == itr)
                    ++itr;
                peopleLeft.erase(otherItr);
            }
            else
                otherItr->second--;
        }
        
        ++boats;
    }

    return boats;
}*/