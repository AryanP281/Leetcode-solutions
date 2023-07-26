
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

int minimumDistance(string word);
int getMinDistance(Vec fingerPos, int i, string& word, int*** dp);
int getDistance(int i, int j);

int main()
{

    cout << minimumDistance("CAKE");

    getchar();
    return 0;
}

int minimumDistance(string word) 
{
    //vector<vector<vector<int>>> dp(word.size(), vector<vector<int>>(26, vector<int>(26, -1)));
    int*** dp = new int**[word.size()];
    for(int i = 0; i < word.size(); ++i)
    {
        dp[i] = new int*[26];
        for(int j = 0; j < 26; ++j)
        {
            dp[i][j] = new int[26];
            for(int k = 0; k < 26; ++k)
            {
                dp[i][j][k] = -1;
            }
        }
    }

    Vec startPos(word[0] - 'A', 0);
    int minDist = INT_MAX;
    for(int c = 0; c < 26; c++)
    {
        startPos.second = c;
        minDist = min(minDist, getMinDistance(startPos, 0, word, dp));
    }

    for(int i = 0; i < word.size(); ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            delete[] dp[i][j];
        }
        delete[] dp[i];
    }
    delete[] dp;

    return minDist;
}

int getMinDistance(Vec fingerPos, int i, string& word, int*** dp)
{
    if(i == word.size())
        return 0;
    else if(dp[i][min(fingerPos.first, fingerPos.second)][max(fingerPos.first, fingerPos.second)] != -1)
        return dp[i][min(fingerPos.first, fingerPos.second)][max(fingerPos.first, fingerPos.second)];

    int a = min(fingerPos.first, fingerPos.second);
    int b = max(fingerPos.first, fingerPos.second);

    int dA = getDistance(a, (int)(word[i] - 'A'));
    int dB = getDistance(b, (int)(word[i] - 'A'));

    int resA = getMinDistance(Vec(b,(int)(word[i] - 'A')), i+1, word, dp);
    int resB = getMinDistance(Vec(a,(int)(word[i] - 'A')), i+1, word, dp); 
    
    dp[i][a][b] = min(dA + resA, dB + resB);
    dp[i][b][a] = dp[i][a][b];

    return dp[i][a][b];
}

int getDistance(int i, int j)
{
    Vec iCoords(i / 6, i % 6);
    Vec jCoords(j / 6, j % 6);

    return abs(iCoords.first - jCoords.first) + abs(iCoords.second - jCoords.second);
}