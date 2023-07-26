/*
#include<iostream>
#include<queue>

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

int maxDiff;

TreeNode* generateTree(int* vals, int n)
{
	TreeNode* root = new TreeNode(vals[0]);

	int i = 1;
	queue<TreeNode*> nodesQueue;
	nodesQueue.push(root);
	while (!nodesQueue.empty() && i < n)
	{
		TreeNode* node = nodesQueue.front();
		nodesQueue.pop();
		
		if (vals[i++] != -1)
		{
			node->left = new TreeNode(vals[i - 1]);
			nodesQueue.push(node->left);
		}
		if (i < n && vals[i++] != -1)
		{
			node->right = new TreeNode(vals[i - 1]);
			nodesQueue.push(node->right);
		}
	}

	return root;
}

void deleteNodes(TreeNode* node)
{
	if (node->left) deleteNodes(node->left);
	if (node->right) deleteNodes(node->right);

	delete node;
}

int maxAncestorDiff(TreeNode* root);
void getMaxDiff(TreeNode* node, int subtreeMax, int subtreeMin);

void main()
{
	int vals[13] = { 8, 3, 10, 1, 6, -1, 14, -1,-1, 4, 7, 13, -1 };
	TreeNode* root = generateTree(vals, 13);

	cout << maxAncestorDiff(root);

	deleteNodes(root);
}

int maxAncestorDiff(TreeNode* root)
{
	maxDiff = 0;
	getMaxDiff(root, root->val, root->val);

	return maxDiff;
}

void getMaxDiff(TreeNode* node, int subtreeMax, int subtreeMin)
{
	if (!node)
	{
		maxDiff = max(subtreeMax - subtreeMin, maxDiff);
		return;
	}

	subtreeMax = max(subtreeMax, node->val);
	subtreeMin = min(subtreeMin, node->val);

	getMaxDiff(node->left, subtreeMax, subtreeMin);
	getMaxDiff(node->right, subtreeMax, subtreeMin);
}
*/