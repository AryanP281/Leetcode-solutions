/*
#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> shortestToChar(string S, char C);

void main()
{
    shortestToChar("aaba", 'b');
}

vector<int> shortestToChar(string S, char C)
{
    vector<int> charPos;
    for (int a = 0; a < S.size(); ++a)
    {
        if (S[a] == C) charPos.push_back(a);
    }

    vector<int> dists;
    int i = 0;
    for (int a = 0; a < S.size(); ++a, i += 1 * (a > charPos[i] && i != charPos.size() - 1))
    {
        int dist;
        if (i != 0)
            dist = min(abs(charPos[i - 1] - a), abs(charPos[i] - a));
        else
            dist = abs(charPos[i] - a);

        dists.push_back(dist);
    }

    return dists;
}
*/