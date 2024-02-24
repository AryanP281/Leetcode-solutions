
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main()
{

    getchar();
    return 0;
}

vector<int> rightSideView(TreeNode* root) 
{

    vector<int> viewedNodes;

    queue<TreeNode*>* currLevel = new queue<TreeNode*>();  
    queue<TreeNode*>* nextLevel = new queue<TreeNode*>(); 
    currLevel->push(root); 

    while(!currLevel->empty())
    {
        while(!currLevel->empty())
        {
            TreeNode* currNode = currLevel->front();
            currLevel->pop();

            if(currLevel->empty())
                viewedNodes.push_back(currNode->val);

            if(currNode->left)
                nextLevel->push(currNode->left);
            if(currNode->right)
                nextLevel->push(currNode->right);
        }

        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new queue<TreeNode*>();
    }     

    delete currLevel;
    delete nextLevel;

    return viewedNodes;
}