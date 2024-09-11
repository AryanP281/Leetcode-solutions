
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

bool isSubtree(TreeNode* root, TreeNode* subRoot);
bool isSameTree(TreeNode* currNode, TreeNode* currSubnode);

TreeNode* generateTree(vector<int>& array)
{
    TreeNode* root = new TreeNode(array[0]);

    queue<TreeNode*>* currLevel = new queue<TreeNode*>();
    currLevel->push(root);
    queue<TreeNode*>* nextLevel = new queue<TreeNode*>();

    int i = 1;
    while(!currLevel->empty())
    {
        while(!currLevel->empty())
        {
            TreeNode* curr = currLevel->front();
            currLevel->pop();

            if(i >= array.size())
                continue;
            else
            {
                if(array[i] > -1001)
                {
                    curr->left = new TreeNode(array[i]);
                    nextLevel->push(curr->left);
                }
                i++;
                if(i <= array.size() && array[i] > -1001)
                {
                    curr->right = new TreeNode(array[i]);
                    nextLevel->push(curr->right);
                }
                i++;
            }
        }

        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new queue<TreeNode*>(); 
    }
    delete currLevel;
    delete nextLevel;

    return root;
}

int main()
{
    vector<int> tArr = {1,1};
    TreeNode* root = generateTree(tArr);
    vector<int> sArr = {1};
    TreeNode* subRoot = generateTree(sArr);

    cout << isSubtree(root, subRoot);

    getchar();
    return 0;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) 
{
    if(isSameTree(root, subRoot))
        return true;

    if(root)
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    
    return false;
}

bool isSameTree(TreeNode* currNode, TreeNode* currSubnode)
{
    if(!currNode)
        return (currSubnode == nullptr);
    else if(!currSubnode)
        return false;
    
    if(currNode->val != currSubnode->val)
        return false;

    bool sameTree = isSameTree(currNode->left, currSubnode->left) && isSameTree(currNode->right, currSubnode->right);
    
    return sameTree;
}

/*

    if(currNode->val == currSubnode->val && dfs(currNode->left, currSubnode->left, subRoot) && dfs(currNode->right, currSubnode->right, subRoot))
        return true;
    else if(currNode->val == subRoot->val) 
        

    return dfs(currNode->left, subRoot, subRoot) || dfs(currNode->right, subRoot, subRoot);
*/