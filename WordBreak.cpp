
#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
    bool isEnd;
    TrieNode* children[26];

    TrieNode()
    {
        isEnd = false;
        fill_n(children, 26, nullptr);
    }

    TrieNode(bool isEnd)
    {
        this->isEnd = isEnd;
        fill_n(children, 26, nullptr);
    }
};

class Trie
{
private:
    TrieNode root;
public:
    Trie() {}

    void insert(string& word)
    {
        TrieNode* curr = & root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(!curr->children[word[i] - 'a'])
                curr->children[word[i]-'a'] = new TrieNode();
            curr =curr->children[word[i]-'a'];
        }
        curr->isEnd = true;
    }

    TrieNode getRoot() const
    {
        return root;
    }
};

bool wordBreak(string s, vector<string>& wordDict);
int canBreak(int i, string& s, TrieNode& root, vector<string>& dict, int* isBreakable);

int main()
{
    string s = "catsandog";
    vector<string> wd = {"cats","dog","sand","and","cat"};
    cout << wordBreak(s,wd);


    getchar();
    return 0;
}

bool wordBreak(string s, vector<string>& wordDict) 
{
    Trie trie;
    for(int i = 0; i < wordDict.size(); ++i)
    {
        trie.insert(wordDict[i]);
    }

    int* isBreakable = new int[s.size()];
    fill_n(isBreakable, s.size(), -1);

    TrieNode trieRoot = trie.getRoot();
    bool breakable = (canBreak(0,s,trieRoot,wordDict,isBreakable) == 1);

    delete[] isBreakable;

    return breakable;
}

int canBreak(int i, string& s, TrieNode& root, vector<string>& dict, int* isBreakable)
{
    if(i == s.size())
        return 1;
    else if(isBreakable[i] != -1)
        return isBreakable[i];

    TrieNode* curr = &root;
    isBreakable[i] = 0;
    for(int j = i; j < s.size() && isBreakable[i] == 0; ++j)
    {
        if(curr->children[s[j] - 'a'] == nullptr)
            break;
        else if(curr->children[s[j] - 'a']->isEnd)
            isBreakable[i] = canBreak(j+1,s,root,dict,isBreakable);

        curr = curr->children[s[j] - 'a'];
    }

    return isBreakable[i];
}