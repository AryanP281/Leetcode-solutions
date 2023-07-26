
#include<bits/stdc++.h>

using namespace std;

vector<int> circularPermutation(int n, int start);

int main()
{
    vector<int> permutation = circularPermutation(3,4);
    for(int a = 0; a < permutation.size(); ++a)
    {
        cout << permutation[a] << ' ';
    }

    getchar();
    return 0;
}

vector<int> circularPermutation(int n, int start) 
{
    int maxNum = pow(2,n)-1;
    
    vector<int> grayCodes;
    grayCodes.reserve(maxNum+1);

    int startPos = 0;
    int gray;
    for(int a = 0; a <= maxNum; ++a)
    {
        gray = a ^ (a >> 1);
        if(gray == start)
            startPos = a;
        grayCodes.push_back(gray);
    }

    vector<int> permutation(maxNum+1, 0);
    permutation[0] = start;
    if(startPos != 0)
        permutation[permutation.size()-1] = grayCodes[startPos-1];

    int i = 1;
    for(int j = startPos+1; j < grayCodes.size(); ++j)
    {
        permutation[i++] = grayCodes[j];
    }

    if(i < permutation.size()-2)
    {
        for(int j = 0; j < startPos-1; ++j,++i)
        {
            permutation[i] = grayCodes[j];
        }
    }

    return permutation;
}