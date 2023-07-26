
#include<bits/stdc++.h>

using namespace std;

vector<string> generateParenthesis(int n);
void getCombinations(int n, vector<string>* cache);

int main()
{
    vector<string> combs = generateParenthesis(4);
    cout << combs.size() << '\n';
    for(int a = 0; a < combs.size(); ++a)
    {
        cout << combs[a] << '\n';
    }

    getchar();
    return 0;
}

vector<string> generateParenthesis(int n) 
{
    vector<string>* cache = new vector<string>[8];
    cache[0].push_back("()");

    getCombinations(n-1, cache);

    return cache[n-1];
}

void getCombinations(int n, vector<string>* cache)
{
    if(cache[n].size() != 0)
        return;

    getCombinations(n-1,cache);

    string currString = "()";
    for(int a = 0; a < cache[n-1].size(); ++a)
    {
        currString.insert(1, cache[n-1][a]);
        cache[n].push_back(currString);
        currString = "()";
    }

    for(int i = n-1; i >= 0; --i)
    {
        for(int j = 0; j < cache[i].size(); ++j, currString = "()")
        {
            currString.insert(0, cache[i][j]);
            if(i != n-1)
            {
                string tempStr = currString;
                for(int k = 0; k < cache[n-2-i].size(); ++k)
                {
                    currString.insert(cache[i][j].size()+1, cache[n-2-i][k]);
                    cache[n].push_back(currString);
                    currString = tempStr;
                }
            }
            else
            {
                cache[n].push_back(currString);
                currString = "()";
            }
        }
    }
}