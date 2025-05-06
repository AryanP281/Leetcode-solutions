
#include<bits/stdc++.h>

using namespace std;

int main()
{


    getchar();

    return 0;
}

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
{
    int* vowelStringCounts = new int[words.size()]();
    vowelStringCounts[0] = 1*(charIsVowel(words[0][0]) && charIsVowel(words[0][words[0].size()-1]));
    for(int i = 1; i < words.size(); ++i)
    {
        vowelStringCounts[i] = vowelStringCounts[i-1] + 1*(charIsVowel(words[i][0]) && charIsVowel(words[i][words[i].size()-1]));
    }
    
    vector<int> result;
    for(int i = 0; i < queries.size(); ++i)
    {
        int queryResult = vowelStringCounts[queries[i][1]];
        if(queries[i][0] != 0)
            queryResult -= vowelStringCounts[queries[i][0]-1];
        result.push_back(queryResult);
    }
    
    delete[] vowelStringCounts;

    return result;
}

bool charIsVowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': return true;
    }

    return false;
}