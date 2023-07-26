/*
#include<iostream>
#include<string>
#include<queue>

using namespace std;

class CombinationIterator
{
private:
    queue<string> combinations;
    string chars;

    void generateCombinations(vector<int>& startPos, int index)
    {
        if(index != 0) startPos[index] = startPos[index - 1] + 1;
        while (startPos[index] <= (chars.size() - (startPos.size() - index)))
        {
            if (index == startPos.size() - 1) combinations.push(createString(startPos));
            else generateCombinations(startPos, index + 1);
            startPos[index]++;
        }
    }

    string createString(vector<int> pos)
    {
        string str = "";
        for (int a = 0; a < pos.size(); ++a)
        {
            str += chars[pos[a]];
        }

        return str;
    }

public:
    CombinationIterator(string characters, int combinationLength)
    {
        chars = characters;
        
        vector<int> pos;
        for (int a = 0; a < combinationLength; ++a)
        {
            pos.push_back(a);
        }

        generateCombinations(pos, 0);
    }

    string next()
    {
        string nextCombi = combinations.front();
        combinations.pop();

        return nextCombi;
    }

    bool hasNext()
    {
        return !combinations.empty();
    }
};

void main()
{
    CombinationIterator ci("chp", 1);

    while (ci.hasNext())
    {
        cout << ci.next() << '\n';
    }
}
*/