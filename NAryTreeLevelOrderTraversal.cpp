
#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root);

int main()
{
    Node* root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    vector<vector<int>> levels = levelOrder(root);
    for(int l = 0; l < levels.size(); ++l)
    {
        for(int n = 0; n < levels[l].size(); ++n)
        {
            cout << levels[l][n] << ' ';
        }
        cout << '\n';
    }

    getchar();
    return 0;
}

vector<vector<int>> levelOrder(Node* root) 
{
    if(!root)
        return vector<vector<int>>();
    
    vector<vector<int>> levels;
    
    queue<Node*>* currLevel = new queue<Node*>();
    currLevel->push(root);
    queue<Node*>* nextLevel = new queue<Node*>();
    while(!currLevel->empty())
    {
        levels.push_back(vector<int>());
        while(!currLevel->empty())
        {
            Node* node = currLevel->front();
            currLevel->pop();

            levels.rbegin()->push_back(node->val);
            for(int a = 0; a < node->children.size(); ++a)
            {
                nextLevel->push(node->children[a]);
            }
        }

        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new queue<Node*>();
    }
    delete currLevel;
    delete nextLevel;

    return levels;   
}