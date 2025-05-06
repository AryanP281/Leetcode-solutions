
#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
    bool isWord;
    struct TrieNode* children[26];

    TrieNode(bool isWord)
    {
        this->isWord = isWord;
        fill_n(children, 26, nullptr);
    }

    TrieNode() : TrieNode(false) {}

    ~TrieNode()
    {
        for(int i = 0; i < 26; ++i)
        {
            if(children[i])
                delete children[i];
        }
    }
};

class Trie
{
private:
    struct TrieNode root;

public:
    Trie() {}

    void addWord(string& word)
    {
        struct TrieNode* currNode = &root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(!currNode->children[word[i] - 'a'])
                currNode->children[word[i]-'a'] = new struct TrieNode();
            currNode = currNode->children[word[i] - 'a'];
        }
        currNode->isWord = true;
    }

    pair<bool,struct TrieNode*> findWord(char ch, struct TrieNode* startNode=nullptr)
    {
        struct TrieNode* currNode = startNode ? startNode : &root;

        if(currNode->children[ch - 'a'] && currNode->children[ch-'a']->isWord)
            return pair<bool, struct TrieNode*>(true, currNode->children[ch-'a']);
        else if(currNode->children[ch - 'a'])
            return pair<bool, struct TrieNode*>(false, currNode->children[ch-'a']);

        return pair<bool, struct TrieNode*>(false, nullptr);
    }
};

vector<string> findAllConcatenatedWordsInADict(vector<string>& words);
bool checkWord(string& word, int i, int8_t* dp, Trie& trie);

int main()
{

    vector<string> words = {"cat","dog","catdog"};
    findAllConcatenatedWordsInADict(words);

    getchar();

    return 0;
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
{
    vector<string> concatenatedWords;
    Trie trie;

    sort(words.begin(), words.end(), [](string& word1, string& word2) -> bool {
        return word1.size() < word2.size();
    });

    for(int i = 0; i < words.size(); ++i)
    {
        int8_t* dp = new int8_t[words[i].size()];
        fill_n(dp, words[i].size(), -1);
        if(checkWord(words[i], 0, dp, trie))
            concatenatedWords.push_back(words[i]);
        else
            trie.addWord(words[i]);
        delete[] dp;
    }

    return concatenatedWords;
}

bool checkWord(string& word, int i, int8_t* dp, Trie& trie)
{
    if(i >= word.size())
        return true;
    if(dp[i] != -1)
        return dp[i];

    typedef pair<bool, struct TrieNode*> SearchResultType;

    SearchResultType sr(false, nullptr);
    dp[i] = 0;
    for(int j = i; j < word.size() && dp[i] == 0; ++j)
    {
        sr = trie.findWord(word[j], sr.second);
        if(sr.first && checkWord(word, j+1, dp, trie))
            dp[i] = 1;
        else if(!sr.first && !sr.second)
            return dp[i];
    }

    return dp[i];
}