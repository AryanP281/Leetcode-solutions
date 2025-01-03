
#include<bits/stdc++.h>

using namespace std;

class RandomizedSet 
{
private:
    unordered_map<int,int> elements;
    vector<int> vals;
    unordered_map<int,int>::iterator itr;

public:
    RandomizedSet() 
    {
        
    }
    
    bool insert(int val) 
    {
        itr = elements.find(val);
        if(itr == elements.end())
        {
            vals.push_back(val);
            elements[val] = vals.size()-1;
            return true;
        }

        return false;
    }
    
    bool remove(int val) 
    {
        itr = elements.find(val);
        if(itr != elements.end())
        {
            elements[*vals.rbegin()] = itr->second;
            vals[itr->second] = *vals.rbegin();
            elements.erase(itr);
            vals.pop_back();
            return true;
        }

        return false;
    }
    
    int getRandom() 
    {
        int i = rand() % vals.size();
        return vals[i];
    }
};

int main()
{

    getchar();
    return 0;
}