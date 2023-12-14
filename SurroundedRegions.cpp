
#include<bits/stdc++.h>

using namespace std;

const int NEIGHBOURS[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; 

void solve(vector<vector<char>>& board);
bool isSurrounded(int r, int c, vector<vector<char>>& board, unordered_set<int>& visited);
void captureRegion(int r, int c, vector<vector<char>>& board);

int main()
{
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(board);

    for(int r = 0; r < board.size(); ++r)
    {
        for(int c = 0; c < board[r].size(); ++c)
        {
            cout << board[r][c];
        }
        cout << endl;
    }

    getchar();
    return 0;
}

void solve(vector<vector<char>>& board) 
{
    for(int r = 0; r < board.size(); ++r)
    {
        for(int c = 0; c < board[r].size(); ++c)
        {
            if(board[r][c] == 'O')
            {
                unordered_set<int> visited;
                visited.insert(r*board[r].size()+c);
                if(isSurrounded(r,c,board,visited))
                    captureRegion(r,c,board);
            }

        }
    }
}

bool isSurrounded(int r, int c, vector<vector<char>>& board, unordered_set<int>& visited)
{
    if(r == 0 || r == board.size() - 1 || c == 0 || c == board[r].size() - 1)
        return false;

    bool surrounded = true;
    int nR, nC;
    for(int i = 0; i < 4 && surrounded; i++)
    {
        nR = r + NEIGHBOURS[i][0];
        nC = c + NEIGHBOURS[i][1];
        if(nR >= 0 && nR < board.size() && nC >= 0 && nC < board[nR].size() && board[nR][nC] == 'O')
        {
            int id = nR*board[nR].size() + nC;
            if(!visited.count(id))
            {
                visited.insert(id);
                surrounded &= isSurrounded(nR, nC, board, visited);
            }
        }
    }
    
    return surrounded;
}

void captureRegion(int r, int c, vector<vector<char>>& board)
{
    board[r][c] = 'X';

    int nR, nC;
    for(int i = 0; i < 4; i++)
    {
        nR = r + NEIGHBOURS[i][0];
        nC = c + NEIGHBOURS[i][1];
        if(nR >= 0 && nR < board.size() && nC >= 0 && nC < board[nR].size() && board[nR][nC] == 'O')
            captureRegion(nR, nC, board);
    }
}