
#include"AvlTree.h"
#include<queue>

AvlTree::AvlTree()
{
	root = nullptr;
	maxSubtreeSizes[nullptr] = -1;
}

AvlTree::~AvlTree()
{
	std::queue<TreeNode*> nodesQueue;
	nodesQueue.push(root);

	while (!nodesQueue.empty())
	{
		TreeNode* node = nodesQueue.front();
		nodesQueue.pop();

		if (node->left != nullptr) nodesQueue.push(node->left);
		if (node->right != nullptr) nodesQueue.push(node->right);

		delete node;
	}
}

void AvlTree::insert(int val)
{
	root = insertIntoTree(val, root);
}

TreeNode* AvlTree::insertIntoTree(int val, TreeNode* root)
{
	if (root == nullptr)
	{
		root = new TreeNode(val);
		maxSubtreeSizes[root] = 0;
		return root;
	}

	if (root->val > val)
		root->left = insertIntoTree(val, root->left);
	else
		root->right = insertIntoTree(val, root->right);

	maxSubtreeSizes[root] = (maxSubtreeSizes[root->left] + 1) * (maxSubtreeSizes[root->left] + 1 > maxSubtreeSizes[root->right] + 1)
		+ (maxSubtreeSizes[root->right] + 1) * (maxSubtreeSizes[root->left] + 1 <= maxSubtreeSizes[root->right] + 1);

	if (!isBalanced(root))
	{
		//Left Subtree
		if (root->val > val)
		{
			//Left Left Case
			if (root->left->val > val)
				root = rightRotation(root);
			//Left Right Case
			else
			{
				root->left = leftRotation(root->left);
				root = rightRotation(root);
			}
		}
		//Right subtree
		else
		{
			//Right Right case
			if (root->right->val < val)
				root = leftRotation(root);
			//Right Left case
			else
			{
				root->right = rightRotation(root->right);
				root = leftRotation(root);
			}
		}
	}

	return root;
}

bool AvlTree::isBalanced(TreeNode* node)
{
	return std::abs(maxSubtreeSizes[node->left] - maxSubtreeSizes[node->right]) <= 1;
}

TreeNode* AvlTree::rightRotation(TreeNode* node)
{
	TreeNode* y = node->left;
	TreeNode* b = y->right;

	y->right = node;
	node->left = b;

	maxSubtreeSizes[node] = maxSubtreeSizes[b] + 1 > maxSubtreeSizes[node->right] + 1 ?
		maxSubtreeSizes[b] + 1 : maxSubtreeSizes[node->right] + 1;
	maxSubtreeSizes[y] = maxSubtreeSizes[node] + 1 > maxSubtreeSizes[y->left] + 1 ?
		maxSubtreeSizes[node] + 1 : maxSubtreeSizes[y->left] + 1;

	return y;
}

TreeNode* AvlTree::leftRotation(TreeNode* node)
{
	TreeNode* y = node->right;
	TreeNode* a = y->left;

	y->left = node;
	node->right = a;

	maxSubtreeSizes[node] = maxSubtreeSizes[a] + 1 > maxSubtreeSizes[node->left] + 1 ?
		maxSubtreeSizes[a] + 1 : maxSubtreeSizes[node->left] + 1;
	maxSubtreeSizes[y] = maxSubtreeSizes[node] + 1 > maxSubtreeSizes[y->right] + 1 ?
		maxSubtreeSizes[node] + 1 : maxSubtreeSizes[y->right] + 1;

	return y;
}