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

TreeNode* increasingBST(TreeNode* root);
TreeNode* traverse(TreeNode* node, TreeNode* newNode);

void main()
{
	TreeNode* root = new TreeNode(5, new TreeNode(3), new TreeNode(6));
	root->left->left = new TreeNode(2, new TreeNode(1), nullptr);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(8, new TreeNode(7), new TreeNode(9));

	increasingBST(root);
}

TreeNode* increasingBST(TreeNode* root)
{
	TreeNode* newRoot = nullptr;
	traverse(root, newRoot);

	return newRoot;
}

TreeNode* traverse(TreeNode* node, TreeNode* newRoot)
{
    if (!node) return nullptr;

    TreeNode* newParent = traverse(node->left, newRoot);
	if (newParent)
	{
		newParent->right = node;
		node->left = nullptr;
	}
	else
	{
		if(!newRoot) newRoot = node;
	}
    node->right = traverse(node->right, newRoot);

    return node->right ? node->right : node;
}
*/