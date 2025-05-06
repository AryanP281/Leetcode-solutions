
#include<bits/stdc++.h>

using namespace std;

vector<int> prisonAfterNDays(vector<int>& cells, int n);

int main()
{

    vector<int> cells = {1,0,0,1,0,0,1,0};
    prisonAfterNDays(cells, 1000000000);

    getchar();

    return 0;
}

vector<int> prisonAfterNDays(vector<int>& cells, int n) 
{
    unordered_map<uint8_t, int> firstOccurrence;
    vector<uint8_t> seenStates;

    uint8_t prevState = 0;
    for(int i = 0; i < cells.size(); ++i)
    {
        prevState |= (cells[i] << (7-i));
    }
    firstOccurrence[prevState] = 0;
    seenStates.push_back(prevState);
    
    uint8_t currState = 0;
    unordered_map<uint8_t,int>::iterator itr;
    for(int currDay = 1; currDay <= n; ++currDay)
    {
        currState = 0;
        for(int i = 1; i < cells.size()-1; ++i)
        {
            uint8_t prevCellState = ((prevState & (1 << 8-i)) >> 8-i);
            uint8_t nextCellState = ((prevState & (1 << 6-i)) >> 6-i);
            if(prevCellState ^ nextCellState == 0)
                currState |= (1 << 7-i);
        }
        
        itr = firstOccurrence.find(currState);
        if(itr != firstOccurrence.end())
        {
            int daysLeft = n - currDay;
            int cycleLen = currDay - itr->second;
            currState = seenStates[itr->second + (daysLeft % cycleLen)];
            break;
        }

        firstOccurrence[currState] = currDay;
        seenStates.push_back(currState);
        
        prevState = currState;
    }

    vector<int> finalState;
    for(int i = 0; i < cells.size(); ++i)
    {
        finalState.push_back((currState & (1 << (7-i))) >> (7-i));
    }

    return finalState;
}