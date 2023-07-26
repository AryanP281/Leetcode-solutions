
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

  TreeNode* invertTree(TreeNode* root);

int main()
{
    TreeNode* root = new TreeNode(4, new TreeNode(2), new TreeNode(7));
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    TreeNode* inverted = invertTree(root);

    getchar();
    return 0;
}

TreeNode* invertTree(TreeNode* root)
{
    if(!root) return root;

    TreeNode* newLeft = invertTree(root->right);
    TreeNode* newRight = invertTree(root->left);
    
    root->left = newLeft;
    root->right = newRight;

    return root;
}