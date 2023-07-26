/*
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

const int neighbourPosVecs[4][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };

bool exist(vector<vector<char>>& board, string word);
bool checkWord(vector<vector<char>>& board, int* pos, string& word, int index, unordered_set<int>);
vector<int*> getNeighbours(vector<vector<char>>& board, int* pos);
bool validCoords(int* coords, int width, int height);

void main()
{
    char brd[3][4] = { {'A','B','C','E'}, {'S','F','E','S'}, {'A','D','E','E'} };
    //char brd[2][2] = { {'a', 'b'}, {'c', 'd'} };
    vector<vector<char>> board;
    for (char a = 0; a < 3; ++a)
    {
        board.push_back(vector<char>());
        for (char b = 0; b < 4; ++b)
        {
            board[a].push_back(brd[a][b]);
        }
    }

    cout << exist(board, "ABCESEEEFS");
}

bool exist(vector<vector<char>>& board, string word)
{
    int pos[2];
    for (int r = 0; r < board.size(); ++r)
    {
        for (int c = 0; c < board[r].size(); ++c)
        {
            unordered_set<int> nodesAlongPath;
            pos[0] = r; pos[1] = c;
            if (checkWord(board, pos, word, 0, nodesAlongPath)) return true;
        }
    }

    return false;
}

bool checkWord(vector<vector<char>>& board, int* pos, string& word, int index, unordered_set<int> nodesAlongPath)
{ 
    if (board[pos[0]][pos[1]] != word[index]) return false;
    else if (index == word.size() - 1) return true;

    nodesAlongPath.insert(pos[0] * board[0].size() + pos[1]);

    vector<int*> neighbours = getNeighbours(board, pos);
    bool wordExists = false;

    for (int a = 0; a < neighbours.size() && !wordExists; ++a)
    {
        if (nodesAlongPath.count(neighbours[a][0] * board[0].size() + neighbours[a][1]) == 1) continue;

        wordExists = checkWord(board, neighbours[a], word, index + 1, nodesAlongPath);
    }

    for (int a = 0; a < neighbours.size(); ++a)
    {
        delete[] neighbours[a];
    }

    return wordExists;
}

vector<int*> getNeighbours(vector<vector<char>>& board, int* pos)
{
    vector<int*> neighbours;
    for (int a = 0; a < 4; ++a)
    {
        int* neighbour = new int[2];
        neighbour[0] = pos[0] + neighbourPosVecs[a][0];
        neighbour[1] = pos[1] + neighbourPosVecs[a][1];

        if (validCoords(neighbour, board[pos[0]].size(), board.size())) neighbours.push_back(neighbour);
        else delete[] neighbour;
    }

    return neighbours;
}

bool validCoords(int* coords, int width, int height)
{
    if (coords[0] >= 0 && coords[0] < height)
    {
        if (coords[1] >= 0 && coords[1] < width) return true;
    }

    return false;
}*/