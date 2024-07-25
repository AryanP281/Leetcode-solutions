
#include<bits/stdc++.h>

using namespace std;

bool generateGraph(vector<string>& words, int l, int r, int d, unordered_map<char,unordered_set<char>>& adjList);
string foreignDictionary(vector<string>& words);
string topologicalSort(unordered_map<char,unordered_set<char>>& adjList);

int main()
{

    //vector<string> words = {"hrn","hrf","er","enn","rfnn"};
    vector<string> words = {"wrtkj","wrt"};
    // vector<string> words = {"er","ern", "erx"};
    cout << foreignDictionary(words);

    getchar();

    return 0;
}

string foreignDictionary(vector<string>& words) 
{
    //Initializing the adjacency list
    unordered_map<char,unordered_set<char>> adjList;
    for(int i = 0; i < words.size(); ++i)
    {
        for(int j = 0; j < words[i].size(); ++j)
        {
            adjList[words[i][j]] = unordered_set<char>();
        }
    }

    if(!generateGraph(words, 0, words.size()-1, 0, adjList))
        return "";

    return topologicalSort(adjList);
}

bool generateGraph(vector<string>& words, int l, int r, int d, unordered_map<char,unordered_set<char>>& adjList)
{
    if(l >= r)
        return true;

    //Discovering edges at current depth
    for(int i = l+1; i <= r; ++i)
    {
        if(words[i][d] != words[i-1][d])
        {
            adjList[words[i-1][d]].insert(words[i][d]);
        }
        else if(words[i].size() < words[i-1].size())
            return false;
    }

    //Recursing to next level
    int nextL = l;
    int nextR = l+1;
    for(; nextR <= r; ++nextR)
    {
        if(words[nextR-1].size()-1 == d || words[nextR][d] != words[nextR-1][d])
        {
            if(!generateGraph(words, nextL, nextR-1, d+1, adjList))
                return false;
            nextL = nextR;
        }
    }
    
    return generateGraph(words, nextL, nextR-1, d+1, adjList);
}

string topologicalSort(unordered_map<char,unordered_set<char>>& adjList)
{
    //Calculating in-degrees of nodes
    unordered_map<char,int> inDegrees;
    for(auto itr1 = adjList.begin(); itr1 != adjList.end(); ++itr1)
    {
        unordered_set<char>& edges = itr1->second;
        for(unordered_set<char>::iterator itr2 = edges.begin(); itr2 != edges.end(); ++itr2)
        {
            inDegrees[*itr2]++;
        }
    }

    //Initializing the set of nodes with zero in-degree
    queue<char> zeroInDegree;
    for(auto itr = adjList.begin(); itr != adjList.end(); ++itr)
    {
        if(inDegrees.find(itr->first) == inDegrees.end())
            zeroInDegree.push(itr->first);
    }

    //Performing topological sorting
    string topSort = "";
    while(!zeroInDegree.empty())
    {
        char currNode = zeroInDegree.front();
        zeroInDegree.pop(); 
        topSort += currNode;

        unordered_set<char>& edges = adjList[currNode];
        for(unordered_set<char>::iterator itr = edges.begin(); itr != edges.end(); ++itr)
        {
            inDegrees[*itr]--;
            if(inDegrees[*itr] == 0)
                zeroInDegree.push(*itr);
        }
    }

    //Checking if there is a valid topological sorting
    for(unordered_map<char,int>::iterator itr = inDegrees.begin(); itr != inDegrees.end(); ++itr)
    {
        if(itr->second != 0)
        {
            topSort = "";
            break;
        }
    }    

    return topSort;
}