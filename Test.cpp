/*
#include "AvlTree.h"
#include<queue>

using namespace std;

TreeNode* balanceBST(TreeNode* root);
void inorderTraversal(TreeNode* currentNode, vector<TreeNode*>& nodes);
TreeNode* formBalancedTree(vector<TreeNode*>& nodes, int l, int r);

void main()
{
	TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2));
	root->right->right = new TreeNode(3, nullptr, new TreeNode(4));

	TreeNode* newRoot = balanceBST(root);

	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* node = q.front();
		q.pop();

		if (node->left != nullptr) q.push(node->left);
		if (node->right != nullptr) q.push(node->right);

		delete node;
	}

}

TreeNode* balanceBST(TreeNode* root)
{
	vector<TreeNode*> inorderNodes;
	inorderTraversal(root, inorderNodes);

	return formBalancedTree(inorderNodes, 0, inorderNodes.size() - 1);
}

void inorderTraversal(TreeNode* currentNode, vector<TreeNode*>& nodes)
{
	/*Inorder traversal returns the nodes sorted according to their value

	if (currentNode == nullptr) return;

	inorderTraversal(currentNode->left, nodes); /*Traversing the left subtree first as 
	nodes in left subtree will have value lower than the root as well as the right subtree 
	and hence will appear earlier in the sorted list

	nodes.push_back(currentNode); //The nodes has valuer higher than left subtree but lower than right subtree

	inorderTraversal(currentNode->right, nodes); //Traversing the right subtree last
}

TreeNode* formBalancedTree(vector<TreeNode*>& nodes, int l, int r)
{
	/*Forms a balanced tree from the given nodes*

	if (l > r) return nullptr;

	int median = (r - l) / 2; //The median index
	TreeNode* root = nodes[l + median]; /*The tree with the median node as the root will be
	the best balanced as it will has equal number of nodes in the left and right subtrees
	root->left = formBalancedTree(nodes, l, l + median - 1); //Balancing the left subtree
	root->right = formBalancedTree(nodes, l + median + 1, r); //Balancing the right subtree

	return root; //Returning root of the best balanced tree
}
*/