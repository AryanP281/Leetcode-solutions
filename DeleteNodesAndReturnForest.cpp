/*
#include<iostream>
#include <vector>

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

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete);
TreeNode* traverse(TreeNode* node, bool* toDel, vector<TreeNode*>& forest);

void main()
{
	TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	int deleteVals[2] = { 3,5 };
	vector<int> to_delete(deleteVals, deleteVals + 2);

	delNodes(root, to_delete);
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
{
	bool delVals[1000] = { false };
	for (auto itr = to_delete.begin(); itr != to_delete.end(); ++itr)
	{
		delVals[(*itr) - 1] = true;
	}
	
	vector<TreeNode*> forest;
	TreeNode* node = traverse(root, delVals, forest);
	if (node) forest.push_back(node);

	return forest;
}

TreeNode* traverse(TreeNode* node, bool* toDel, vector<TreeNode*>& forest)
{
	if (!node) return nullptr;

	if (toDel[node->val - 1])
	{
		TreeNode* leftTree = traverse(node->left, toDel, forest);
		if (leftTree) forest.push_back(leftTree);
		TreeNode* rightTree = traverse(node->right, toDel, forest);
		if (rightTree) forest.push_back(rightTree);

		return nullptr;
	}

	node->left = traverse(node->left, toDel, forest);
	node->right = traverse(node->right, toDel, forest);

	return node;
}
*/