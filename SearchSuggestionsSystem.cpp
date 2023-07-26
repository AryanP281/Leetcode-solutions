
#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
    TrieNode* nextNodes[26];
    bool isEndOfWord;

    TrieNode(bool isEnd)
    {
        isEndOfWord = isEnd;
        for(int a = 0; a < 26; ++a)
        {
            nextNodes[a] = nullptr;
        }
    }
};

class Trie
{
private :
    TrieNode* root;

    void dfs(TrieNode* currNode, string& currWord, vector<string>& suggestions)
    {
        if(suggestions.size() == 3)
            return;
        else if(currNode->isEndOfWord)
            suggestions.push_back(currWord);

        for(int a = 0; a < 26 && suggestions.size() != 3; ++a)
        {
            if(!currNode->nextNodes[a])
                continue;
            
            currWord += (char)('a'+a);
            dfs(currNode->nextNodes[a], currWord, suggestions);
            currWord.pop_back();
        }
    }

    void deleteNodes(TrieNode* currNode)
    {
        for(int a = 0; a < 26; ++a)
        {
            if(currNode->nextNodes[a])
                deleteNodes(currNode->nextNodes[a]);
        }

        delete currNode;
    }

public :
    Trie()
    {
        root = new TrieNode(false);
    }

    ~Trie()
    {
        deleteNodes(root);
    }

    void insertWord(string& word)
    {
        TrieNode* currNode = root;
        for(int a = 0; a < word.size(); ++a)
        {
            if(!currNode->nextNodes[word[a]-'a'])
                currNode->nextNodes[word[a]-'a'] = new TrieNode(false);
            currNode = currNode->nextNodes[word[a]-'a'];
        }

        currNode->isEndOfWord = true;
    }

    void getSuggestions(string& keyword, int r, vector<string>& suggestions)
    {
        TrieNode* currNode = root;
        string currWord = "";
        for(int a = 0; a < r; a++)
        {
            if(!currNode->nextNodes[keyword[a]-'a'])
                return;
            currNode = currNode->nextNodes[keyword[a]-'a'];
            currWord += keyword[a];
        }

        dfs(currNode, currWord, suggestions);
    }
};

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) ;

int main()
{

    vector<string> products = {"havana"};
    vector<vector<string>> suggestions = suggestedProducts(products, "tatiana");
    for(int a = 0; a < suggestions.size(); ++a)
    {
        for(int b = 0; b < suggestions[a].size(); ++b)
        {
            cout << suggestions[a][b] << ' ';
        }
        cout << '\n';
    }

    getchar();
    return 0;
}

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
{
    Trie trie;
    for(int a = 0; a < products.size(); ++a)
    {
        trie.insertWord(products[a]);
    }

    vector<vector<string>> suggestions(searchWord.size(), vector<string>());
    for(int a = 1; a <= searchWord.size(); ++a)
    {
        trie.getSuggestions(searchWord, a, suggestions[a-1]);
    }

    return suggestions;

}