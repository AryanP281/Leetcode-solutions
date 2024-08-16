#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
    bool isWordEnd;
    TrieNode* children[26];

    TrieNode() : TrieNode(false) {}

    TrieNode(bool isWordEnd)
    {
        this->isWordEnd = isWordEnd;
        fill_n(children, 26, nullptr);
    }
};

class WordDictionary 
{
private:
    TrieNode root;

    bool find(TrieNode* currNode, int i, string& word)
    {
        if(!currNode)
            return false;
        else if(i >= word.size())
            return currNode->isWordEnd;

        if(word[i] == '.')
        {
            for(int j = 0; j < 26; ++j)
            {
                if(currNode->children[j] && find(currNode->children[j], i+1, word))
                    return true;
            }
            return false;
        }

        return currNode->children[word[i]-'a'] && find(currNode->children[word[i] - 'a'], i+1, word);
    }

public:
    WordDictionary() {
        
    }
    
    void addWord(string word) 
    {
        TrieNode* currNode = &root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(!currNode->children[word[i]-'a'])
                currNode->children[word[i]-'a'] = new TrieNode();
            currNode = currNode->children[word[i]-'a'];
        }

        currNode->isWordEnd = true;
    }
    
    bool search(string word) 
    {
        TrieNode* curr = &root;
        return this->find(curr, 0, word);
    }
};

int main()
{
    WordDictionary wd;
    cout << wd.search(".");

    getchar();
    return 0;
}

