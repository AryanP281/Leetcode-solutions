
#include<bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isWord;

    TrieNode()
    {
        for(int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
TrieNode* constructTrie(vector<string>& words);
bool dfs(int currPos, TrieNode* currTrieNode, string& currString, unordered_set<string>& foundWords, vector<vector<char>>& grid,bool* visited);

int main()
{
    vector<vector<char>> board = {{'a','b'},{'c','d'}};
    vector<string> words = {"abcb"};

    findWords(board, words);

    getchar();
    return 0;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
    TrieNode* trieRoot = constructTrie(words);

    unordered_set<string> foundWords;
    bool* visited = new bool[board.size()*board[0].size()]();
    for(int i = 0; i < board.size()*board[0].size(); ++i)
    {
        string wordString = "";
        dfs(i, trieRoot, wordString, foundWords, board, visited);
    }

    delete[] visited;

    vector<string> result;
    for(unordered_set<string>::iterator itr = foundWords.begin(); itr != foundWords.end(); ++itr)
    {
        result.push_back(*itr);
    }

    return result;
}

TrieNode* constructTrie(vector<string>& words)
{
    TrieNode* root = new TrieNode();
    for(int i = 0; i < words.size(); ++i)
    {
        TrieNode* currNode = root;
        for(int j = 0; j < words[i].size(); ++j)
        {
            if(!currNode->children[words[i][j] - 'a'])
                currNode->children[words[i][j] - 'a'] = new TrieNode();
            currNode = currNode->children[words[i][j] - 'a'];
        }
        currNode->isWord = true;
    }

    return root;
}

bool dfs(int currPos, TrieNode* currTrieNode, string& currString, unordered_set<string>& foundWords, vector<vector<char>>& grid, bool* visited)
{
    int r= floor(currPos / grid[0].size());
    int c = currPos % grid[0].size();

    if(!currTrieNode->children[grid[r][c] - 'a'])
        return false;
    
    visited[currPos] = true;
    currString += grid[r][c];
    if(currTrieNode->children[grid[r][c] - 'a']->isWord)
        foundWords.insert(currString);

    const int NEIGHBOURS[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    for(int i = 0; i < 4; ++i)
    {
        int nR = r + NEIGHBOURS[i][0];
        int nC = c + NEIGHBOURS[i][1];

        if(nR >= 0 && nR < grid.size() && nC >= 0 && nC < grid[nR].size())
        {
            int n = nR*grid[0].size()+nC; 
            if(!visited[n] && dfs(n, currTrieNode->children[grid[r][c] - 'a'], currString, foundWords, grid, visited))
                currString.pop_back();
        }
        
    }

    visited[currPos] = false;
    return true;
}