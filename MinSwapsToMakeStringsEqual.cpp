
#include<bits/stdc++.h>

using namespace std;

int minimumSwap(string s1, string s2);

int main()
{
    string s1 = "xxyyxyxyxx";
    string s2 = "xyyxyxxxyx";

    cout << minimumSwap(s1,s2);

    getchar();
    return 0;
}

int minimumSwap(string s1, string s2) 
{
    int xyCombinations = 0;
    int yxCombinations = 0;

    for(int a = 0; a < s1.size(); ++a)
    {
        if(s1[a] == 'x' && s2[a] == 'y')
            ++xyCombinations;
        else if(s1[a] == 'y' && s2[a] == 'x')
            ++yxCombinations;
    }

    //{"xx","yy"} => 1 swap, {"xy","yx"} => 2 swaps

    if((xyCombinations % 2) + (yxCombinations % 2) == 1) //After merging all "xx" and "yy" only one "xy" or "yx" is left which cannot be solved
        return -1;

    return (xyCombinations / 2) + (yxCombinations / 2) + 2*((xyCombinations % 2) == 1);   
}