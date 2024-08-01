
#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

int main()
{


    getchar();
    return 0;
}

Node* cloneGraph(Node* node) 
{
    if(!node)
        return nullptr;

    unordered_map<int,Node*> cloned;

    return dfs(node, cloned);
}

Node* dfs(Node* curr, unordered_map<int,Node*>& cloned)
{
    if(!curr)
        return nullptr;
    
    unordered_map<int,Node*>::iterator itr = cloned.find(curr->val);
    if(itr != cloned.end())
        return itr->second;

    cloned[curr->val] = new Node(curr->val);
    itr = cloned.find(curr->val);
    for(int i = 0; i < curr->neighbors.size(); ++i)
    {
        itr->second->neighbors.push_back(dfs(curr->neighbors[i], cloned));
    }

    return itr->second;
}