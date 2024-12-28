
#include<bits/stdc++.h>

using namespace std;

string pushDominoes(string dominoes);

int main()
{

    cout << pushDominoes("RR.L");

    getchar();
    return 0;
}

string pushDominoes(string dominoes) 
{
    int** distances = new int*[2];
    distances[0] = new int[dominoes.size()];
    distances[1] = new int[dominoes.size()];

    int domPos = -1;
    for(int i = 0; i < dominoes.size(); ++i)
    {
        if(dominoes[i] == 'R')
            domPos = i;
        else if(dominoes[i] == 'L')
            domPos = -1;

        distances[0][i] = dominoes.size()*(domPos == -1) + (i - domPos)*(domPos != -1);
    }

    domPos = -1;
    for(int i = dominoes.size()-1; i >= 0; --i)
    {
        if(dominoes[i] == 'L')
            domPos = i;
        else if(dominoes[i] == 'R')
            domPos = -1;

        distances[1][i] = dominoes.size()*(domPos == -1) + (domPos-i)*(domPos != -1);
    }

    string finalState = "";
    for(int i = 0; i < dominoes.size(); ++i)
    {
        switch (dominoes[i])
        {
            case 'R': finalState += 'R'; break;
            case 'L': finalState += 'L'; break;
            case '.': {
                if(distances[0][i] < distances[1][i])
                    finalState += 'R';
                else if(distances[0][i] > distances[1][i])
                    finalState += 'L';
                else
                    finalState += '.';
            }; break;
        }
    }
    

    delete[] distances[0];
    delete[] distances[1];
    delete[] distances;

    return finalState;        
}