
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  };

TreeNode* subtreeWithAllDeepest(TreeNode* root);
bool traverse(TreeNode* node, int depth, pair<TreeNode*,int>& deepest);

TreeNode* constructTree(vector<int>& arr)
{
    if(arr.size() == 0)
        return nullptr;
    
    TreeNode* root = new TreeNode(arr[0]);

    queue<TreeNode*> nodes;
    nodes.push(root);

    for(int i = 1; i < arr.size(); ++i)
    {
        TreeNode* currNode = nodes.front();
        nodes.pop();

        if(arr[i++] != -1)
        {
            currNode->left = new TreeNode(arr[i-1]);
            nodes.push(currNode->left);
        }
        if(arr[i] != -1)
        {
            currNode->right = new TreeNode(arr[i]);
            nodes.push(currNode->right);
        }
    }

    return root;
}

int main()
{
    //vector<int> vals = {3,5,1,6,2,0,8,-1,-1,7,4};
    vector<int> vals = {1};
    TreeNode* root = constructTree(vals);

    TreeNode* smallestRoot = subtreeWithAllDeepest(root);
    cout << smallestRoot->val;

    getchar();
    return 0;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) 
{
    unordered_map<int,TreeNode*> parentNodes;

    vector<TreeNode*>* currLevel = new vector<TreeNode*>();
    vector<TreeNode*>* nextLevel = new vector<TreeNode*>();
    nextLevel->push_back(root);
    while(!nextLevel->empty())
    {
        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new vector<TreeNode*>();

        for(int a = 0; a < currLevel->size(); ++a)
        {
            if(currLevel->at(a)->left)
            {
                nextLevel->push_back(currLevel->at(a)->left);
                parentNodes[currLevel->at(a)->left->val] = currLevel->at(a);
            }
            if(currLevel->at(a)->right)
            {
                nextLevel->push_back(currLevel->at(a)->right);
                parentNodes[currLevel->at(a)->right->val] = currLevel->at(a);
            }
        }
    }

    unordered_set<int> currDeepestNodeVals;
    queue<TreeNode*> currDeepestNodes;
    unordered_set<int>::iterator itr;
    for(int a = 0; a < currLevel->size(); ++a)
    {
        currDeepestNodeVals.insert(currLevel->at(a)->val);
        currDeepestNodes.push(currLevel->at(a));
    }
    delete currLevel;
    delete nextLevel;

    int initialSize;
    TreeNode* currNodeParent;
    while(currDeepestNodes.size() > 1)
    {
        initialSize = currDeepestNodes.size();
        for(int a = 0; a < initialSize; ++a)
        {
            currNodeParent = parentNodes[currDeepestNodes.front()->val];
            itr = currDeepestNodeVals.find(currNodeParent->val);
            if(itr == currDeepestNodeVals.end())
            {
                currDeepestNodeVals.insert(currNodeParent->val);
                currDeepestNodes.push(currNodeParent);
            }
            currDeepestNodeVals.erase(currDeepestNodes.front()->val);
            currDeepestNodes.pop();
        }
    }

    return (currDeepestNodes.size() ? currDeepestNodes.front() : root);
}
