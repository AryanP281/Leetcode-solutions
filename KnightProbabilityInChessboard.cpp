
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec2D;

double knightProbability(int N, int K, int r, int c);
void play(double** probs, int n, int k, Vec2D& pos);

const int MOV_VECS[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2,1}, {2, -1}, {1, -2}};

int main()
{

    cout << knightProbability(3,2,0,0);

    getchar();
    return 0;
}

double knightProbability(int N, int K, int r, int c) 
{
    int cells = N*N;
    double** probs = new double*[cells];
    for(int a = 0; a < cells; ++a)
    {
        probs[a] = new double[K+1]();
    }
    probs[r*N+c][0] = 1.0;

    for(int k = 0; k < K;++k)
    {
        for(int a = 0; a < cells; ++a)
        {
            Vec2D coords(a / N, a % N);
            for(int b = 0; b < 8; ++b)
            {
                Vec2D moveCoords(coords.first+MOV_VECS[b][0], coords.second+MOV_VECS[b][1]);
                if(moveCoords.first >= 0 && moveCoords.first < N && moveCoords.second >= 0 && moveCoords.second < N)
                {
                    int index = (moveCoords.first*N) + moveCoords.second;
                    probs[index][k+1] += probs[a][k] / 8.0;
                    index = 0;    
                }
            }
        }
    }

    double totalProb = 0.0;
    for(int a = 0; a < cells; ++a)
    {
        totalProb += probs[a][K];
        delete[] probs[a];
    }
    delete[] probs;

    return totalProb;
}
