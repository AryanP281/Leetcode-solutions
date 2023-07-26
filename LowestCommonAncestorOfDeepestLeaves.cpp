/*
#include <iostream>

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

void deleteNodes(TreeNode* node)
{
	if (node->left) deleteNodes(node->left);
	if (node->right) deleteNodes(node->right);

	delete node;
}

TreeNode* lcaDeepestLeaves(TreeNode* root);
int getAncestor(TreeNode* node, int depth, TreeNode** ancestor);

int maxDepth = 0;

void main()
{
	TreeNode* root = new TreeNode(1, new TreeNode(2), nullptr);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4, new TreeNode(5), nullptr);

	lcaDeepestLeaves(root);

	deleteNodes(root);
}

TreeNode* lcaDeepestLeaves(TreeNode* root) 
{
	maxDepth = INT_MIN;
	TreeNode* ancestor = nullptr;
	getAncestor(root, 0, &ancestor);

	return ancestor;
}

int getAncestor(TreeNode* node, int depth, TreeNode** ancestor)
{
	if (!node) return depth;

	int lDepth = getAncestor(node->left, depth + 1, ancestor);
	int rDepth = getAncestor(node->right, depth + 1, ancestor);

	if (lDepth == rDepth && lDepth >= maxDepth)
	{
		*ancestor = node;
		maxDepth = lDepth;
	}

	return lDepth > rDepth ? lDepth : rDepth;
}
*/