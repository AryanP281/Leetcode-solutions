
#include<bits/stdc++.h>

using namespace std;

int candy(vector<int>& ratings);

int main()
{
    vector<int> ratings = {1,2,2};
    cout << candy(ratings);

    getchar();
    
    return 0;
}

int candy(vector<int>& ratings) 
{
    const int N = ratings.size();

    unordered_map<int,unordered_set<int>> adjList;

    int* inDegrees = new int[N]();
    for(int i = 1; i < ratings.size(); ++i)
    {
        if(ratings[i-1] < ratings[i])
        {
            adjList[i-1].insert(i);
            inDegrees[i]++;
        }
        else if(ratings[i-1] > ratings[i])
        {
            adjList[i].insert(i-1);
            inDegrees[i-1]++;
        }
    }

    int* candies = new int[N];
    fill_n(candies,N, 1);
    queue<int> relaxedNodes;
    for(int i = 0; i < N; ++i)
    {
        if(inDegrees[i] == 0)
            relaxedNodes.push(i);
    }

    while(!relaxedNodes.empty())
    {
        int node = relaxedNodes.front();
        relaxedNodes.pop();
        
        unordered_map<int,unordered_set<int>>::iterator itr = adjList.find(node);
        if(itr != adjList.end())
        {
            for(auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
            {
                inDegrees[*itr2]--;
                candies[*itr2] = max(candies[*itr2], candies[node]+1);
                if(inDegrees[*itr2] == 0)
                    relaxedNodes.push(*itr2);
            }
        }
    }

    int totalCandies = 0;
    for(int i = 0; i < N; ++i)
    {
        totalCandies += candies[i];
    }

    delete[] candies;

    return totalCandies;
}