
#include<bits/stdc++.h>

using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power);

int main()
{

    vector<int> tokens = {100,200,300,400};
    cout << bagOfTokensScore(tokens, 200);

    getchar();
    return 0;
}

int bagOfTokensScore(vector<int>& tokens, int power) 
{
    sort(tokens.begin(), tokens.end());
    
    int currScore = 0;
    int currPower = power;
    int bestScore = currScore;
    int l = 0;
    int r = tokens.size()-1;
    while(l <= r)
    {
        if(tokens[l] <= currPower)
        {
            currPower -= tokens[l++];
            currScore++;
        }
        else if(currScore > 0)
        {
            currPower += tokens[r--];
            currScore--;
        }
        else
            break;
        
        bestScore = max(bestScore, currScore);
    }

    return bestScore;
}