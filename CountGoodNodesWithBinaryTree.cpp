
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

int goodNodes(TreeNode* root);
int dfs(TreeNode* currNode, int currMax);

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1, new TreeNode(3), nullptr);
    root->right = new TreeNode(4, new TreeNode(1), new TreeNode(5));

    cout << goodNodes(root);

    getchar();
    return 0;
}

int goodNodes(TreeNode* root) 
{
    return dfs(root, INT_MIN);     
}

int dfs(TreeNode* currNode, int currMax)
{
   if(!currNode)
    return 0;

    int goodNodes = 1*(currMax <= currNode->val);
    currMax = max(currMax, currNode->val);
    goodNodes += dfs(currNode->left, currMax) + dfs(currNode->right, currMax);

    return goodNodes;
}