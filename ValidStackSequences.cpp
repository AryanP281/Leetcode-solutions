
#include<bits/stdc++.h>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped);

int main()
{
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,3,5,1,2};
    cout << validateStackSequences(pushed, popped);

    getchar();
    return 0;
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
{
    list<int> sequence;
    int pushOrder[1001] = {-1};
    for(int i = 0; i < pushed.size(); ++i)
    {
        sequence.push_back(pushed[i]);
        pushOrder[pushed[i]] = i;
    }
    
    list<int>::iterator currHead = sequence.begin();

    for(int i = 0; i < popped.size(); ++i)
    {
        if(currHead != prev(sequence.begin()) && popped[i] == *currHead)
        {}
        else if(currHead != prev(sequence.begin()) && pushOrder[popped[i]] < pushOrder[*currHead])
            return false;
        else
        {
            while(currHead == prev(sequence.begin()) || *currHead != popped[i])
                currHead++;
        }

        list<int>::iterator temp = prev(currHead);
        sequence.erase(currHead);
        currHead = temp;
    }

    return true;
}