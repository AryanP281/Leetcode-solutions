
#include<bits/stdc++.h>

using namespace std;

int numMatchingSubseq(string s, vector<string>& words);
bool subsequenceExists(string& word, vector<int>* chars);
int binarySearchForUpper(vector<int>& indices, int start);

int main()
{
    string str = "abcde";
    vector<string> words = {"a","bb","acd","ace"};
    cout << numMatchingSubseq(str, words);

    getchar();
    return 0;
}

int numMatchingSubseq(string s, vector<string>& words) 
{
    vector<int>* charPositions = new vector<int>[26];
    for(int8_t a = 0; a < 26; ++a)
    {
        charPositions[a].reserve(s.size());
    }

    for(int a = 0; a < s.size(); ++a)
    {
        charPositions[s[a]-'a'].push_back(a);
    }

    int subsequenceCount = 0;
    for(int a = 0; a < words.size(); ++a)
    {
        subsequenceCount += 1*(subsequenceExists(words[a], charPositions));
    }

    delete[] charPositions;

    return subsequenceCount;
}

bool subsequenceExists(string& word, vector<int>* chars)
{
    int currPos = -2;
    for(int i = 0; i < word.size() && currPos != -1; ++i)
    {
        currPos = binarySearchForUpper(chars[word[i] - 'a'], currPos);
    }

    return (currPos != -1);
}

int binarySearchForUpper(vector<int>& indices, int start)
{   
    if(!indices.size())
        return -1;

    int currMinpos = -1;
    int mid;
    int l = 0;
    int r = indices.size();
    while(l <= r)
    {
        mid = floor((l+r)/2);
        if(indices[mid] > start)
        {
            currMinpos = indices[mid];
            r = mid-1;
        }
        else
            l = mid+1;
    }

    return currMinpos;
}