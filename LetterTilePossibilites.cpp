/*
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>

using namespace std;

int combinations;
int maxLen;
vector<string> combs;
unordered_set<string> seenCombs;

int numTilePossibilities(string tiles);
void getAllCombinations(string startString, queue<char> availableChars);

void main()
{
    cout << numTilePossibilities("AAB");
}

int numTilePossibilities(string tiles)
{
    combinations = -1;
    maxLen = tiles.size();
    queue<char> chars;
    for (int a = 0; a < tiles.size(); ++a)
    {
        chars.push(tiles[a]);
    }

    seenCombs.insert(tiles);
    getAllCombinations("", chars);

    return combinations;
}

void getAllCombinations(string startString, queue<char> availableChars)
{
    if (seenCombs.count(startString) == 1) return;
    
    ++combinations;
    seenCombs.insert(startString);

    if (startString.size() == maxLen) return;

    int i = availableChars.size();
    while (i-- > 0)
    {
        char newChar = availableChars.front();
        availableChars.pop();

        getAllCombinations(startString + newChar, availableChars);

        availableChars.push(newChar);
    }
}
*/