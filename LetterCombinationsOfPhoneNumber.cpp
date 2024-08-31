
#include<bits/stdc++.h>

using namespace std;

const string digitMap[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> letterCombinations(string digits);
void generateCombos(int i, string& currCombo, string& digits, vector<string>& combos);

int main()
{
    letterCombinations("2");

    getchar();
    return 0;
}

vector<string> letterCombinations(string digits) 
{
    if(digits.size() == 0)
        return {};
    
    vector<string> combos;
    string currCombo = "";

    generateCombos(0, currCombo, digits, combos);

    return combos;
}

void generateCombos(int i, string& currCombo, string& digits, vector<string>& combos)
{
    if(i == digits.size())
    {
        combos.push_back(currCombo);
        return;
    }

    for(int j = 0; j < digitMap[digits[i] - '2'].size(); ++j)
    {
        currCombo += digitMap[digits[i] - '2'][j];
        generateCombos(i+1,currCombo,digits,combos);
        currCombo.pop_back();
    }
}