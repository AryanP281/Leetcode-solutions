
#include<bits/stdc++.h>

using namespace std;

int snakesAndLadders(vector<vector<int>>& board);
int getMinSteps(int currPos, int prevState, vector<vector<int>>& board, bool* visited, int** dp, vector<int>* posMap);

int main()
{
    vector<vector<int>> board = {{-1,-1,-1,-1,48,5,-1},{12,29,13,9,-1,2,32},{-1,-1,21,7,-1,12,49},{42,37,21,40,-1,22,12},{42,-1,2,-1,-1,-1,6},{39,-1,35,-1,-1,39,-1},{-1,36,-1,-1,-1,-1,5}};
    cout << snakesAndLadders(board);

    getchar();

    return 0;
}

int snakesAndLadders(vector<vector<int>>& board) 
{
    const int N = board.size();

    typedef pair<int,int> Vec;

    vector<int>* posMap = new vector<int>[N * N];
    int currPos = 1;
    bool reversed = false;
    for (int r = N - 1; r >= 0; --r, reversed = !reversed)
    {   
        int c = reversed ? N - 1 : 0;
        for (; (reversed && c >= 0) || (!reversed && c < N); c = reversed ? c - 1 : c + 1)
        {
            posMap[currPos - 1] = {r, c};
            currPos++;
        }
    }

    bool* visited = new bool[N * N]();
    visited[0] = true;

    queue<Vec> q;
    q.push(Vec(1,0));

    while(!q.empty())
    {
        Vec currPos = q.front();
        q.pop();

        for(int i = 1; i <= 6; ++i)
        {
            int nextPos = currPos.first + i;
            int nextR = posMap[nextPos-1][0];
            int nextC = posMap[nextPos-1][1];

            if(board[nextR][nextC] != -1)
                nextPos = board[nextR][nextC];

            if(nextPos == N*N)
                return currPos.second+1;
            
            if(!visited[nextPos-1])
            {
                visited[nextPos-1] = true;
                q.push(Vec(nextPos,currPos.second+1));
            }
        }
    }

    return -1;
}
