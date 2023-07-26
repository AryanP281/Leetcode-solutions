
#include<bits/stdc++.h>

using namespace std;

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes);

int main()
{
    vector<int> status = {1,1,1};
    vector<int> candies = {2,3,2};
    vector<vector<int>> keys = {{},{},{}};
    vector<vector<int>> containedBoxes = {{},{},{}};
    vector<int> initalBoxes = {2,1,0};

    cout << maxCandies(status, candies, keys, containedBoxes, initalBoxes);

    getchar();
    return 0;
}

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
{
    unordered_set<int> unopened;
    list<int> open;

    for(int i = 0; i < initialBoxes.size(); ++i)
    {
        if(status[initialBoxes[i]])
            open.push_back(initialBoxes[i]);
        else
            unopened.insert(initialBoxes[i]);
    }
    
    int ownedCandies = 0;
    int currBox;
    while(!open.empty())
    {
        currBox = *open.begin();
        open.pop_front();

        ownedCandies += candies[currBox];
        candies[currBox] = 0;

        for(int i = 0; i < keys[currBox].size(); ++i)
        {
            status[keys[currBox][i]] = 1;
            if(unopened.count(keys[currBox][i]))
            {
                open.push_back(keys[currBox][i]);
                unopened.erase(keys[currBox][i]);
            }
        }

        for(int i = 0; i < containedBoxes[currBox].size(); ++i)
        {
            if(status[containedBoxes[currBox][i]])
                open.push_back(containedBoxes[currBox][i]);
            else
                unopened.insert(containedBoxes[currBox][i]);
        }
    }

    return ownedCandies;   
}