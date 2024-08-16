
#include<bits/stdc++.h>

using namespace std;

int main()
{

    getchar();
    return 0;
}

vector<int> plusOne(vector<int>& digits) 
{
    digits.insert(digits.begin(), 0);

    vector<int> result;
    int currCarry = 1; 
    for(int i = digits.size()-1; i >= 0; i--)
    {
        result.push_back((digits[i]+currCarry) % 10);
        currCarry = floor((double)(digits[i]+currCarry)/10.0);
    }

    if(*(result.rbegin()) == 0)
        result.pop_back();

    reverse(result.begin(), result.end());
    return result;
}