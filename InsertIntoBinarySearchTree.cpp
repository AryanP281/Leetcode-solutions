/*
#include<iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val);
void insert(TreeNode** root, int val);

void main()
{
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	TreeNode* newRoot = insertIntoBST(root, 5);
}

TreeNode* insertIntoBST(TreeNode* root, int val)
{
	insert(&root, val);

	return root;
}

void insert(TreeNode** root, int val)
{
    if (*root == nullptr)
    {
        *root = new TreeNode(val);
        return;
    }

    if ((*root)->val > val) insert((*root)->left, val);
    else insert((*root)->right, val);
}*/