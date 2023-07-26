
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

TreeNode* reverseOddLevels(TreeNode* root);

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

void printTree(TreeNode* curr)
{
    if(!curr)
        return;

    cout << curr->val << ',';
    printTree(curr->left);
    printTree(curr->right);
}

int main()
{
    vector<int> treeVals = {0,1,2,0,0,0,0,1,1,1,1,2,2,2,2};
    TreeNode* root = constructTree(treeVals);
    TreeNode* modified = reverseOddLevels(root);

    printTree(modified);

    getchar();
    return 0;
}

TreeNode* reverseOddLevels(TreeNode* root) 
{
    vector<TreeNode*>* currLevel = new vector<TreeNode*>();
    vector<TreeNode*>* nextLevel = new vector<TreeNode*>();

    currLevel->push_back(root);
    
    int i = 0;
    while(!currLevel->empty())
    {
        while(!currLevel->empty())
        {
            TreeNode* currNode = currLevel->back();
            currLevel->pop_back();

            if(currNode->left)
                nextLevel->push_back(currNode->left);
            if(currNode->right)
                nextLevel->push_back(currNode->right);
        }

        if(!(i++ % 2))
        {
            for(int j = 0; j < floor((float)nextLevel->size() / 2.0f); ++j)
            {
                int temp = nextLevel->operator[](j)->val;
                nextLevel->operator[](j)->val = nextLevel->operator[](nextLevel->size()-1-j)->val;
                nextLevel->operator[](nextLevel->size()-1-j)->val = temp;
            }
        }

        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new vector<TreeNode*>();
    }

    delete currLevel;
    delete nextLevel;

    return root;
}