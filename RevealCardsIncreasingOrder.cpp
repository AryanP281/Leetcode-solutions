/*
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck);

void main()
{
    int vals[7] = { 17,13,11,2,3,5,7 };
    vector<int> deck(vals, vals + 7);

    vector<int> order = deckRevealedIncreasing(deck);
}

vector<int> deckRevealedIncreasing(vector<int>& deck)
{
    sort(deck.begin(), deck.end());
    queue<int> nextPos;
    for (int a = 0; a < deck.size(); ++a)
    {
        nextPos.push(a);
    }

    vector<int> order(deck.size(), 0);
    vector<int>::iterator itr = deck.begin();
    while (!nextPos.empty())
    {
        order[nextPos.front()] = *itr;
        nextPos.pop();
        ++itr;

        if (!nextPos.empty())
        {
            nextPos.push(nextPos.front());
            nextPos.pop();
        }
    }

    return order;
}
*/
