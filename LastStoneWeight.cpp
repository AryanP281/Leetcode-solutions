
#include<bits/stdc++.h>

using namespace std;

int main()
{


    getchar();
    return 0;
}

int lastStoneWeight(vector<int>& stones) 
{
    priority_queue<int> heap;
    for(int i = 0; i < stones.size(); ++i)
    {
        heap.push(stones[i]);
    }

    while(heap.size() > 1)
    {
        int f = heap.top();
        heap.pop();
        int s = heap.top();
        heap.pop();

        if(f != s)
            heap.push(f - s);
    }

    if(heap.size())
        return heap.top();

    return 0;
}