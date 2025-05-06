
#include<bits/stdc++.h>

using namespace std;

int totalFruit(vector<int>& fruits);

int main()
{

    vector<int> fruits = {1,2,3,2,2};
    cout << totalFruit(fruits);

    getchar();

    return 0;
}

int totalFruit(vector<int>& fruits) 
{
    unordered_map<int,int> currFruits;
    unordered_map<int,int>::iterator itr;
    
    int maxFruits = 0;
    int l = 0;
    for(int r = 0; r < fruits.size(); ++r)
    {
        itr = currFruits.find(fruits[r]);
        if(itr == currFruits.end())
        {
            if(currFruits.size() < 2)
                currFruits[fruits[r]] = 1;
            else
            {
                maxFruits = max(maxFruits, (currFruits.begin())->second + (next(currFruits.begin()))->second);
                while(l < r && currFruits.size() == 2)
                {
                    itr = currFruits.find(fruits[l++]);
                    itr->second--;
                    if(itr->second == 0)
                        currFruits.erase(itr);
                }
                currFruits[fruits[r]] = 1; 
            }
        }
        else
            itr->second++;
    }

    if(currFruits.size() == 2)
        maxFruits = max(maxFruits, (currFruits.begin())->second + (next(currFruits.begin()))->second);
    else if(currFruits.size()==1)
        maxFruits = max(maxFruits, currFruits.begin()->second);

    return maxFruits;
}