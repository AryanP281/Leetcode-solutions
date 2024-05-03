
#include<bits/stdc++.h>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList);
pair<int,int> generateGraph(vector<string>& words, bool** adjMatrix,string& start, string& end);

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << ladderLength(beginWord, endWord, wordList);

    getchar();
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    wordList.push_back(beginWord);

    bool** adjMatrix = new bool*[wordList.size()];
    for(int i = 0; i < wordList.size(); ++i)
    {
        adjMatrix[i] = new bool[wordList.size()]();
    }

    pair<int,int> srcDest = generateGraph(wordList, adjMatrix, beginWord, endWord);
    int shortestSeq = 0;
    bool endFound = false;
    if(srcDest.second != -1)
    {
        queue<int>* currLevel = new queue<int>();
        currLevel->push(srcDest.first);
        queue<int>* nextLevel = new queue<int>();
        bool* visited = new bool[wordList.size()]();
        visited[srcDest.first] = true;

        while(!currLevel->empty() && !endFound)
        {
            shortestSeq++;
            while(!currLevel->empty())
            {
                int currNode = currLevel->front();
                currLevel->pop();

                if(currNode == srcDest.second)
                {
                    endFound = true;
                    break;
                }

                for(int i = 0; i < wordList.size(); ++i)
                {
                    if(adjMatrix[currNode][i] && !visited[i])
                    {
                        nextLevel->push(i);
                        visited[i] = true;
                    }
                }
            }

            delete currLevel;
            currLevel = nextLevel;
            nextLevel = new queue<int>();
        }


        delete currLevel;
        delete nextLevel;
    }

    for(int i = 0; i < wordList.size(); ++i)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    wordList.pop_back();

    if(!endFound)
        return 0;

    return shortestSeq;
}

pair<int,int> generateGraph(vector<string>& words, bool** adjMatrix, string& start, string& end)
{
    unordered_map<string,int> nodeIds;
    unordered_map<string,int>::iterator itr;

    int currNodeId = 0;
    for(int i = 0; i < words.size(); ++i, currNodeId++)
    {
        for(int j = 0; j < words[i].size(); ++j)
        {
            char orgChar = words[i][j];
            for(char ch = 'a'; ch <= 'z'; ++ch)
            {
                if(ch == orgChar)
                    continue;
                words[i][j] = ch;
                itr = nodeIds.find(words[i]);
                if(itr != nodeIds.end())
                {
                    adjMatrix[itr->second][currNodeId] = true;
                    adjMatrix[currNodeId][itr->second] = true;
                }
            }
            words[i][j] = orgChar;
        }
        nodeIds[words[i]] = currNodeId;
    }

    itr = nodeIds.find(end);
    if(itr == nodeIds.end())
        return pair<int,int>(nodeIds[start], -1);        
    return pair<int,int>(nodeIds[start], itr->second);
}   