
#include<bits/stdc++.h>

using namespace std;

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount);

int main()
{
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    vector<int> amount = {-2,4,2,-4,6};
    cout << mostProfitablePath(edges, 3, amount);

    getchar();
    return 0;
}

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
{
    unordered_map<int,vector<int>> adjList;
    unordered_map<int,vector<int>>::iterator itr;
    for(int i = 0; i < edges.size(); i++)
    {
        itr = adjList.find(edges[i][0]);
        if(itr == adjList.end())
            adjList[edges[i][0]] = {edges[i][1]};
        else
            itr->second.push_back(edges[i][1]);

        itr = adjList.find(edges[i][1]);
        if(itr == adjList.end())
            adjList[edges[i][1]] = {edges[i][0]};
        else
            itr->second.push_back(edges[i][0]);
    }
    
    unordered_map<int,vector<int>> bobVisitOrder;
    bobVisitOrder[bob] = {bob,0};
    queue<int>* currQueue = new queue<int>();
    queue<int>* nextQueue = new queue<int>();
    currQueue->push(bob);
    bool rootFound = false;
    while(!currQueue->empty() && !rootFound)
    {
        while(!currQueue->empty())
        {
            int currNode = currQueue->front();
            currQueue->pop();

            if(currNode == 0)
            {
                rootFound = true;
                break;
            }
                
            itr = adjList.find(currNode);
            unordered_map<int,vector<int>>::iterator currVisitOrder = bobVisitOrder.find(currNode);
            for(int i = 0; i < itr->second.size(); ++i)
            {
                if(bobVisitOrder.count((itr->second)[i]))
                    continue;
                
                nextQueue->push((itr->second)[i]);
                bobVisitOrder[(itr->second)[i]] = {currNode, currVisitOrder->second[1]+1};
            }
        }

        delete currQueue;
        currQueue = nextQueue;
        nextQueue = new queue<int>();
    }

    delete currQueue;
    delete nextQueue;

    unordered_map<int,int> bobPath;
    unordered_map<int,vector<int>>::iterator currPathNode = bobVisitOrder.find(0);
    while(1)
    {
        bobPath[currPathNode->first] = currPathNode->second[1];
        if(currPathNode->second[0] == currPathNode->first)
            break;

        currPathNode = bobVisitOrder.find(currPathNode->second[0]);
    }

    unordered_map<int,vector<int>> aliceVisitOrder;
    aliceVisitOrder[0] = {0,amount[0]};
    currQueue = new queue<int>();
    currQueue->push(0);
    nextQueue = new queue<int>();
    while(!currQueue->empty())
    {
        while(!currQueue->empty())
        {
            int currNode = currQueue->front();
            currQueue->pop();

            itr = adjList.find(currNode);
            unordered_map<int,vector<int>>::iterator currVisitOrder = aliceVisitOrder.find(currNode);
            unordered_map<int,int>::iterator bobVisitOrder;
            for(int i = 0; i < itr->second.size(); ++i)
            {
                if(aliceVisitOrder.count(itr->second[i]))
                    continue;
                bobVisitOrder = bobPath.find(itr->second[i]);
                if(bobVisitOrder == bobPath.end() || bobVisitOrder->second > currVisitOrder->second[0]+1)
                    aliceVisitOrder[itr->second[i]] = {currVisitOrder->second[0]+1, currVisitOrder->second[1]+amount[itr->second[i]]};
                else if(bobVisitOrder->second < currVisitOrder->second[0]+1)
                    aliceVisitOrder[itr->second[i]] = {currVisitOrder->second[0]+1,currVisitOrder->second[1]};
                else
                    aliceVisitOrder[itr->second[i]] = {currVisitOrder->second[0]+1,currVisitOrder->second[1]+(amount[itr->second[i]]/2)};
                
                nextQueue->push(itr->second[i]);
            }
        }

        delete currQueue;
        currQueue = nextQueue;
        nextQueue = new queue<int>();
    }

    delete currQueue;
    delete nextQueue;

    int maxIncome = INT_MIN;
    for(itr = adjList.begin(); itr != adjList.end(); ++itr)
    {
        if(itr->second.size() == 1 && itr->first != 0)
            maxIncome = max(maxIncome, aliceVisitOrder[itr->first][1]);
    }

    return maxIncome;
}