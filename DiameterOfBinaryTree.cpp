
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Vec;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode* left, TreeNode* right)
    {
        val = x;
        this->left = left;
        this->right = right;
    }
};

int diameterOfBinaryTree(TreeNode* root) ;
Vec getDiameter(TreeNode* currNode);
TreeNode* getTree(vector<int>& vals);

int main()
{
    vector<int> vals = {4,-7,-3,101,101,-9,-3,9,-7,-4,101,6,101,-6,-6,101,101,0,6,5,101,9,101,101,-1,-4,101,101,101,-2};
    TreeNode* root = getTree(vals);

    cout << diameterOfBinaryTree(root);

    getchar();
    return 0;
}

int diameterOfBinaryTree(TreeNode* root) 
{
    return getDiameter(root).second;
}

Vec getDiameter(TreeNode* currNode)
{
    if(!currNode)
        return Vec(0,0);

    Vec leftRes = getDiameter(currNode->left);
    Vec rightRes = getDiameter(currNode->right);

    Vec currRes(max(leftRes.first, rightRes.first)+1, max(leftRes.first+rightRes.first, max(leftRes.second, rightRes.second)));

    return currRes;
}

TreeNode* getTree(vector<int>& vals)
{
    if(!vals.size())
        return nullptr;
    
    TreeNode* root = new TreeNode(vals[0]);
    
    queue<TreeNode*>* currLevel = new queue<TreeNode*>();
    currLevel->push(root);
    queue<TreeNode*>* nextLevel = new queue<TreeNode*>();
    
    TreeNode* currNode;
    int i = 1;
    while(!currLevel->empty())
    {
        while(!currLevel->empty())
        {
            currNode = currLevel->front();
            currLevel->pop();

            if(i < vals.size() && vals[i] != 101)
            {
                currNode->left = new TreeNode(vals[i]);
                nextLevel->push(currNode->left);
            }
            ++i;
            if(i < vals.size() && vals[i] != 101)
            {
                currNode->right = new TreeNode(vals[i]);
                nextLevel->push(currNode->right);
            }
            ++i;
        }

        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new queue<TreeNode*>();
    }

    delete currLevel;
    delete nextLevel;

    return root;
}