
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

const int FINAL_STATE = 0x054321;
const Vec nextVecs[] = {Vec(0,-1), Vec(-1,0), Vec(0,1), Vec(1,0)};

int slidingPuzzle(vector<vector<int>>& board);

int main()
{

    vector<vector<int>> board = {{3,2,4}, {1,5,0}};
    cout << slidingPuzzle(board);

    getchar();
    return 0;
}

int slidingPuzzle(vector<vector<int>>& board) 
{
    
    queue<int>* currLevel = new queue<int>();
    queue<int>* nextLevel = new queue<int>();

    int currState = 0;
    for(int r = 0; r < board.size(); ++r)
    {
        for(int c = 0; c < board[r].size(); ++c)
        {
            currState |= (board[r][c] << (4*(r*board[r].size()+c)));
        }
    }

    unordered_set<int> seenStates;
    int movesCount = -1;
    int newState;

    currLevel->push(currState);
    while(!currLevel->empty())
    {
        movesCount++;
        while(!currLevel->empty())
        {
            currState = currLevel->front();
            currLevel->pop();

            if(seenStates.count(currState))
                continue;
            
            if(currState == FINAL_STATE)
            {
                delete currLevel;
                delete nextLevel;
                return movesCount;
            }

            seenStates.insert(currState);

            for(int8_t i = 0; i < board.size()*board[0].size(); ++i)
            {
                if((currState & (7 << (4*i))) == 0)
                {
                    int r = (i / board[0].size());
                    int c = (i % board[0].size());
                    for(int8_t j = 0; j < 4; ++j)
                    {
                        if(r + nextVecs[j].first >= 0 && r + nextVecs[j].first < board.size())
                        {
                            if(c + nextVecs[j].second >= 0 && c + nextVecs[j].second < board[r].size())
                            {
                                int r_n = r+nextVecs[j].first;
                                int c_n = c+nextVecs[j].second;
                                
                                newState = currState;
                                int a = (currState & (7 << 4*(3*r_n+c_n))) >> (4*(3*r_n+c_n));
                                newState |= (a << 4*i);
                                newState &= ~(7 << (4*(r_n*3+c_n)));

                                nextLevel->push(newState);
                            }
                        }
                    }
                    break;
                }
            }
        }

        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new queue<int>();
    }
    delete currLevel;
    delete nextLevel;
    
    return -1;
}