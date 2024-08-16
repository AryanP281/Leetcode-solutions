
#include<bits/stdc++.h>

using namespace std;

typedef vector<int> Vec;

bool exist(vector<vector<char>>& board, string word);
bool dfs(Vec currPos, int i, string& word, vector<vector<char>>& board, bool** visited);

int main()
{
    vector<vector<char>> brd = {{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},
    {'A','A','A','A','A','B'},{'A','A','A','A','B','A'}};

    cout << exist(brd,"AAAAAAAAAAAAAAB");

    getchar();
    return 0;
}

bool exist(vector<vector<char>>& board, string word) 
{
    bool** visited = new bool*[board.size()];
    for(int r = 0; r < board.size(); ++r)
    {
        visited[r] = new bool[board[r].size()]();
    }

    bool wordExists = false;
    for(int r = 0; r < board.size() && !wordExists; ++r)
    {
        for(int c = 0; c < board[r].size() && !wordExists; ++c)
        {
            wordExists = dfs({r,c}, 0, word, board, visited);
        }
    }


    for(int r = 0; r < board.size(); ++r)
    {
        delete[] visited[r];
    }
    delete[] visited;

    return wordExists;
}

bool dfs(Vec currPos, int i, string& word, vector<vector<char>>& board, bool** visited)
{
    if(i == word.size())
        return true;
    else if(!(currPos[0] >= 0 && currPos[0] < board.size() && currPos[1] >= 0 && currPos[1] < board[0].size()))
        return false;
    else if(board[currPos[0]][currPos[1]] != word[i] || visited[currPos[0]][currPos[1]])
        return false;
    
    const int NEIGHBOURS[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    bool wordExists = false;
    visited[currPos[0]][currPos[1]] = true;
    for(int j = 0; j < 4 && !wordExists; ++j)
    {
        Vec neigh = {currPos[0]+NEIGHBOURS[j][0],currPos[1]+NEIGHBOURS[j][1]};
        wordExists = dfs(neigh, i+1, word, board, visited);
    }

    visited[currPos[0]][currPos[1]] = false;
    return wordExists;
}