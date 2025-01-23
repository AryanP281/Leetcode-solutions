
#include<bits/stdc++.h>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass);

int main()
{
    cout << champagneTower(25,6,1); 

    getchar();

    return 0;
}

double champagneTower(int poured, int query_row, int query_glass) 
{
    vector<double>* currLevel = new vector<double>();
    vector<double>* nextLevel = new vector<double>(2);

    currLevel->push_back(poured);
    for(int r = 0; r < query_row; ++r)
    {
        for(int c = 0; c < currLevel->size(); ++c)
        {
            double extraFlow = (*currLevel)[c] - 1.0;
            if(extraFlow > 0.0)
            {
                (*nextLevel)[c] += extraFlow / 2.0;
                (*nextLevel)[c+1] += extraFlow / 2.0;
            }
            
        }
        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new vector<double>(currLevel->size()+1);
    }

    double result = min(1.0, (*currLevel)[query_glass]);

    delete currLevel;
    delete nextLevel;

    return result;
}