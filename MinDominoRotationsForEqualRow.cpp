
#include<bits/stdc++.h>

using namespace std;

int minDominoRotations(vector<int>& tops, vector<int>& bottoms);

int main()
{

    vector<int> tops = {3,5,1,2,3};
    vector<int> bottoms = {3,6,3,3,4};

    cout << minDominoRotations(tops, bottoms);

    getchar();
    return 0;
}

int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
{
    int** freqs = new int*[3];
    for(int8_t a = 0; a < 3; ++a)
    {
        freqs[a] = new int[6]();
    }

    for(int a = 0; a < tops.size(); ++a)
    {
        freqs[0][tops[a]-1]++;
        freqs[1][bottoms[a]-1]++;
        freqs[2][tops[a]-1] += 1*(tops[a] == bottoms[a]);
    }

    int n = tops.size();
    int minRotations = n+1;
    for(int8_t i = 0; i < 6; ++i)
    {
        if(n - freqs[0][i] == (freqs[1][i] - freqs[2][i]))
            minRotations = min(minRotations, n - freqs[0][i]);
        if(n - freqs[1][i] == (freqs[0][i] - freqs[2][i]))
            minRotations = min(minRotations, n - freqs[1][i]);
    }

    for(int8_t a = 0; a < 3; ++a)
    {
        delete[] freqs[a];
    }
    delete[] freqs;

    return (minRotations == (n+1)) ? -1 : minRotations;
}

