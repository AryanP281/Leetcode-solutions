
#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
    TrieNode* nextNodes[26];
    bool isEndOfWord;
    int counts;

    TrieNode(bool isEnd)
    {
        isEndOfWord = isEnd;
        for(int a = 0; a < 26; ++a)
        {
            nextNodes[a] = nullptr;
        }
        counts = 0;
    }
};

class Trie
{
private :    
    TrieNode* root;

    void deleteTrie(TrieNode* node)
    {
        for(int a = 0; a < 26; ++a)
        {
            if(node->nextNodes[a])
                deleteTrie(node->nextNodes[a]);
        }
        delete node;
    }

public :
    Trie()
    {
        root = new TrieNode(false);
    }

    ~Trie()
    {
        deleteTrie(root);
    }

    void insert(string& key)
    {
        TrieNode* currNode = root;
        for(int a = 0; a < key.size(); ++a)
        {
            int charIndex = key[a] - 'a';
            if(!currNode->nextNodes[charIndex])
                currNode->nextNodes[charIndex] = new TrieNode(false);
            
            currNode = currNode->nextNodes[charIndex];
        }

        currNode->isEndOfWord = true;
        currNode->counts++;
    }

    int search(string& key)
    {
        TrieNode* currNode = root;
        for(int a = 0; a < key.size(); ++a)
        {
            int charIndex = key[a] - 'a';
            if(!currNode->nextNodes[charIndex])
                return false;
            currNode = currNode->nextNodes[charIndex];
        }

        if(currNode && currNode->isEndOfWord)
            return currNode->counts;

        return 0;
    }
};

int countSubstrings(string s, string t);
void generateSubstrings(string& str, forward_list<string>* container);
void constructTrie(forward_list<string>& keys, Trie& trie);

int main()
{
    string s = "aba";
    string t = "baba";
    cout << countSubstrings(s,t);

    getchar();
    return 0;
}

int countSubstrings(string s, string t) 
{
    forward_list<string> tSubstrs;
    generateSubstrings(t, &tSubstrs);
    Trie trie;
    constructTrie(tSubstrs, trie);

    forward_list<string> sSubstrs;
    generateSubstrings(s,&sSubstrs);

    int substringsCount = 0;
    forward_list<string>::iterator itr = sSubstrs.begin();
    while(itr != sSubstrs.end())
    {
        for(int a = 0; a < itr->size(); ++a)
        {
            char originalChar = itr->at(a);
            for(char b = 'a'; b <= 'z'; ++b)
            {
                if(b == originalChar) continue;
                itr->operator[](a) = b;
                substringsCount += trie.search(*itr);
            }
            itr->operator[](a) = originalChar;
        }
        ++itr;
    }

    return substringsCount;
}

void generateSubstrings(string& str, forward_list<string>* container)
{
    for(int i = 0; i < str.size(); ++i)
    {
        string substr(1,str[i]);
        container->push_front(substr);
        for(int j = i+1; j < str.size(); ++j)
        {
            substr += str[j];
            container->push_front(substr);
        }
    }
}

void constructTrie(forward_list<string>& keys, Trie& trie)
{
    forward_list<string>::iterator itr = keys.begin();
    while(itr != keys.end())
    {
        trie.insert(*itr);
        itr++;
    }
}