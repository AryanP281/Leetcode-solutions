
#include<bits/stdc++.h>

using namespace std;
class NestedInteger {
    public:
        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const;

        // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const;

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const vector<NestedInteger> &getList() const;
};

class NestedIterator 
{
private:
    vector<int> flattenedArray;
    int currPos;
    
    void flatten(const vector<NestedInteger>& currLevel)
    {
        if(currLevel.empty())
            return;

        for(int i = 0; i < currLevel.size(); ++i)
        {
            if(currLevel[i].isInteger())
                flattenedArray.push_back(currLevel[i].getInteger());
            else
                flatten(currLevel[i].getList());
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        flatten(nestedList);
        currPos = 0;
    }
    
    int next() 
    {
        return flattenedArray[currPos++];    
    }
    
    bool hasNext() 
    {
        return (currPos < flattenedArray.size());    
    }
};

int main()
{


    getchar();

    return 0;
}

