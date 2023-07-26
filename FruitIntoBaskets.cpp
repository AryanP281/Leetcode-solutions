
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int totalFruit(vector<int>& fruits);

int main()
{
    vector<int> fruits = {1,1,2,3,3,2,2,4,4,4,4,1};
    cout << totalFruit(fruits);

    getchar();
    return 0;
}

int totalFruit(vector<int>& fruits) 
{
    unordered_map<int,int> baskets;
    int l = 0;
    int r = 0;
    for(; r < fruits.size(); ++r)
    {
        if(!baskets.count(fruits[r]))
        {
            if(baskets.size() != 2)
                baskets.insert(Vec(fruits[r], 1));
            else
                break;
        }
        else
            baskets[fruits[r]]++;
    }
    r--;

    int maxFruits = baskets.begin()->second;
    if(baskets.size() > 1)
        maxFruits += (++baskets.begin())->second;

    unordered_map<int,int>::iterator itr;
    while(++r < fruits.size())
    {
        itr = baskets.find(fruits[r]);
        if(itr == baskets.end() && baskets.size() == 2)
        {
            maxFruits = max(maxFruits, baskets.begin()->second + (++baskets.begin())->second);
            while(baskets.size() == 2)
            {
                itr = baskets.find(fruits[l++]);
                itr->second--;
                if(itr->second == 0)
                    baskets.erase(itr);
            }
        }
        
        baskets[fruits[r]]++;
    }

    maxFruits = max(maxFruits, baskets.size()==2 ? baskets.begin()->second + (++baskets.begin())->second : baskets.begin()->second);

    return maxFruits;
}