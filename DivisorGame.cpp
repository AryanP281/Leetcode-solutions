
#include<bits/stdc++.h>

using namespace std;

bool divisorGame(int N);
vector<int> getFactors(int x);

int main()
{

    cout << (divisorGame(6) ? "True" : "False") << '\n';

    getchar();
    return 0;
}

bool divisorGame(int N) 
{
    /*
        cache[i] = true if the starting player can win when N=i.
        Thus, cache[i] = true iff for any factor 'f' of i cache[i-f] = false as by choosing 'f' an unwinnable state will be 
        created for the next player 
    */
    
    bool* cache = new bool[N]();
    cache[0] = false;

    for(int a = 1; a < N; ++a)
    {
        vector<int> facs = getFactors(a+1);
        for(int b = 0; b < facs.size(); ++b)
        {
            int newNumIndex = a - facs[b];
            if(!cache[newNumIndex])
            {
                cache[a] = true;
                break;
            }
        }
    }

    bool alexWins = cache[N-1];
    delete[] cache;

    return alexWins;   
}

vector<int> getFactors(int x)
{
    int sqr = ceil(sqrt(x));

    vector<int> factors;
    factors.push_back(1);
    for(int a = 2; a <= sqr; ++a)
    {
        if(x%a == 0)
            factors.push_back(a);
    }

    return factors;
}