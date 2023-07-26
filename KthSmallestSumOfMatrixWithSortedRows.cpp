
#include<bits/stdc++.h>

using namespace std;

struct State
{
    int sum;
    int* cols;

    State()
    {
        sum = 0;
        cols = nullptr;
    }

    State(int sum, int* cols)
    {
        this->sum = sum;
        this->cols = cols;
    }
};

class Cmp
{
public:
    bool operator()(State& s1, State& s2)
    {
        return s1.sum > s2.sum;
    }
};

int kthSmallest(vector<vector<int>>& mat, int k);

int main()
{
    vector<vector<int>> mat = {{1,1,10}, {2,2,9}};
    cout << kthSmallest(mat, 7);

    getchar();
    return 0;
}

int kthSmallest(vector<vector<int>>& mat, int k) 
{
    int m = mat.size();
    priority_queue<State, vector<State>, Cmp> heap;

    int currSum = 0;
    for(int r = 0; r < mat.size(); ++r)
    {
        currSum += mat[r][0];
    }
    State startState(currSum, new int[mat.size()]());
    heap.push(startState);

    unordered_set<string> visitedStates;

    State currState;
    for(int currK = 0; currK != k; ++currK)
    {
        currState = heap.top();
        heap.pop();

        for(int i = 0; i < mat.size(); ++i)
        {
            if(currState.cols[i] == mat[i].size()-1)
                continue;

            State newState(currState.sum + (mat[i][currState.cols[i]+1] - mat[i][currState.cols[i]]), new int[mat.size()]);
            string stateStr = "";
            for(int j = 0; j < mat.size(); ++j)
            {
                if(j == i)
                    newState.cols[j] = currState.cols[i]+1;
                else
                    newState.cols[j] = currState.cols[j];
                stateStr += to_string(newState.cols[j]) + ",";
            }

            if(!visitedStates.count(stateStr))
            {
                heap.push(newState);
                visitedStates.insert(stateStr);
            }
        }
    }

    return currState.sum;
}