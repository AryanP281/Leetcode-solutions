#include<bits/stdc++.h>

using namespace std;

vector<string> findItinerary(vector<vector<string>>& tickets);
void dfs(string curr, unordered_map<string,vector<string>>& adjList, vector<string>& itrnStack);

int main()
{
    vector<vector<string>> tickets {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    findItinerary(tickets);

    getchar();
    return 0;
}

vector<string> findItinerary(vector<vector<string>>& tickets) 
{
    unordered_map<string,vector<string>> adjList;
    for(int i = 0; i < tickets.size(); i++)
    {
        unordered_map<string,vector<string>>::iterator itr = adjList.find(tickets[i][0]);
        if(itr == adjList.end())
            adjList[tickets[i][0]] = vector<string>();
        adjList[tickets[i][0]].push_back(tickets[i][1]);
    }
    for(auto itr = adjList.begin(); itr != adjList.end(); ++itr)
    {
        sort(itr->second.begin(), itr->second.end());
        reverse(itr->second.begin(), itr->second.end());
    }

    //Hierholzer's algorithm to find eulerian circuit/path. O(E)
    vector<string> itinerary;
    dfs("JFK", adjList, itinerary);
    reverse(itinerary.begin(), itinerary.end());

    return itinerary;
}

void dfs(string curr, unordered_map<string,vector<string>>& adjList, vector<string>& itrnStack)
{
    
    vector<string>& out = adjList[curr];
    while(!out.empty())
    {
        string next = *out.rbegin();
        out.pop_back();
        dfs(next, adjList, itrnStack);
    }

    itrnStack.push_back(curr);
}
