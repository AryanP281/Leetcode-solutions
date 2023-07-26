
#include<bits/stdc++.h>

using namespace std;

int scoreOfParentheses(string S);

int main()
{
    string str = "(()(()))";
    cout << scoreOfParentheses(str);

    getchar();
    return 0;
}

int scoreOfParentheses(string S) 
{
    typedef pair<int,int> Vec;
    
    stack<int> openingBracPos;
    stack<Vec> scores;

    int currScore;
    for(int a = 0; a < S.size(); ++a)
    {
        if(S[a] == '(')
            openingBracPos.push(a);
        else
        {
            currScore = 0;
            while(!scores.empty() && scores.top().second > openingBracPos.top())
            {
                currScore += scores.top().first;
                scores.pop();
            }

            currScore = max(1, currScore * 2);
            scores.push(Vec(currScore, openingBracPos.top()));
            openingBracPos.pop();
        }
    }

    int totalScore = 0;
    while(!scores.empty())
    {
        totalScore += scores.top().first;
        scores.pop();
    }

    return totalScore;   
}