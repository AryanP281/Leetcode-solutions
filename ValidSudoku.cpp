
#include<bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board);

int main()
{
    vector<vector<char>> board = {{'8','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};

    cout << isValidSudoku(board);

    getchar();
    return 0;
}

bool isValidSudoku(vector<vector<char>>& board) 
{
    int16_t* rowMasks = new int16_t[9]();
    int16_t* colMasks = new int16_t[9]();
    int16_t* subMatrixMasks = new int16_t[9]();

    int bitMask = 0;
    for(int r = 0; r < 9; ++r)
    {
        for(int c = 0; c < 9; ++c)
        {
            if(board[r][c] == '.')
                continue;
            
            bitMask = (1 << (board[r][c]-'0'-1)); 
            
            if(rowMasks[r] & bitMask)
                return false;
            if(colMasks[c] & bitMask)
                return false;

            int sbR = 3 * floor(r / 3);
            int sbC = floor(c / 3);
            if(subMatrixMasks[sbR + sbC] & bitMask)
                return false;
            
            rowMasks[r] |= bitMask;
            colMasks[c] |= bitMask;
            subMatrixMasks[sbR + sbC] |= bitMask;
        }
    }

    delete[] colMasks;
    delete[] rowMasks;
    delete[] subMatrixMasks;

    return true;
}