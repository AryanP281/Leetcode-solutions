
#include<bits/stdc++.h>

using namespace std;

class FreqStack 
{
private :
    unordered_map<int,int> freqs;
    unordered_map<int, forward_list<int>> freqOrder;
    int currMaxFreq;


public:
    FreqStack() 
    {
        currMaxFreq = 0;    
    }
    
    void push(int val) 
    {
        unordered_map<int,int>::iterator itr = freqs.find(val);
        if(itr == freqs.end())
        {
            freqs[val] = 1;
            freqOrder[1].push_front(val);
            currMaxFreq = max(currMaxFreq, 1);
        }
        else
        {
            itr->second++;
            freqOrder[itr->second].push_front(val);
            currMaxFreq = max(currMaxFreq, itr->second);
        }

    }
    
    int pop() 
    {
        unordered_map<int, forward_list<int>>::iterator itr = freqOrder.find(currMaxFreq);

        int poppedVal = itr->second.front();    
        freqs[poppedVal]--;    
        itr->second.pop_front();
        if(itr->second.empty())
            currMaxFreq--;

        return poppedVal;
    }

};


int main()
{
    FreqStack* obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);

    for(int i = 0; i < 6; ++i)
    {
        cout << obj->pop() << '\n';
    }

    delete obj;

    getchar();
    return 0;
}

/*
struct Vec
{
    int val;
    int topPos;

    Vec(int val, int topPos)
    {
        this->val = val;
        this->topPos = topPos;
    }

    bool operator<(const Vec& other) const
    {
        return this->topPos > other.topPos;
    }

};

class FreqStack 
{
private :
    unordered_map<int, int> freqs;
    unordered_map<int, list<int>> positions;
    map<int, set<Vec>, greater<int>> freqOrder;
    int currTopPos;

public:
    FreqStack() 
    {
        currTopPos = 0;
    }
    
    void push(int val) 
    {
        unordered_map<int,int>::iterator itr = freqs.find(val);

        if(itr == freqs.end())
        {
            freqOrder[1].insert(Vec(val, currTopPos));
            freqs[val] = 1;
            positions[val].push_front(currTopPos);
        }
        else
        {
            freqOrder[itr->second].erase(Vec(val, positions[val].front()));
            freqOrder[itr->second+1].insert(Vec(val, currTopPos));
            positions[val].push_front(currTopPos);
            freqs[val]++;
        }

        ++currTopPos;    
    }
    
    int pop() 
    {
        while(freqOrder.begin()->second.empty())
        {
            freqOrder.erase(freqOrder.begin());
        }
        
        Vec popped = *(freqOrder.begin()->second.begin());
        freqOrder.begin()->second.erase(freqOrder.begin()->second.begin());

        unordered_map<int,list<int>>::iterator itr = positions.find(popped.val);
        itr->second.pop_front();
        if(itr->second.empty())
        {
            positions.erase(popped.val);
            freqs.erase(popped.val);
        }
        else
        {
            freqOrder[freqOrder.begin()->first-1].insert(Vec(popped.val, itr->second.front()));
            freqs[popped.val]--;
        }

        return popped.val;
    }
    
};
*/