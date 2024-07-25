
#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
    TrieNode* children[26];
    bool isEndWord;
    TrieNode()
    {
        fill_n(children, 26, nullptr);
        isEndWord = false;
    }
};

class Trie 
{
private:
    TrieNode root;    
public:
    Trie() 
    {
        root = TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode* currNode = &root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(!currNode->children[word[i] - 'a'])
                currNode->children[word[i] - 'a'] = new TrieNode();
            currNode = currNode->children[word[i] - 'a'];
        }    
        currNode->isEndWord = true;
    }
    
    bool search(string word) 
    {
        TrieNode* currNode = &root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(!currNode->children[word[i] - 'a'])
                return false;
            currNode = currNode->children[word[i] - 'a'];
        }    
        
        return currNode->isEndWord;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* currNode = &root;
        for(int i = 0; i < prefix.size(); ++i)
        {
            if(!currNode->children[prefix[i] - 'a'])
                return false;
            currNode = currNode->children[prefix[i] - 'a'];
        }    

        return true;    
    }
};

int main()
{

    getchar();
    return 0;
}