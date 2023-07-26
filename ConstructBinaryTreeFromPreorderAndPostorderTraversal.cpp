/*
#include<iostream>
#include<vector>

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
	if (!node) return;

	deleteNodes(node->left);
	deleteNodes(node->right);

	delete node;
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post);
TreeNode* construct(int* preIndex, int* postIndex);

vector<int>* preorder;
vector<int>* postorder;

void main()
{
	vector<int> pre = { 1,2,4,5,3,6,7 };
	vector<int> post = { 4,5,2,6,7,3,1 };

	TreeNode* root = constructFromPrePost(pre, post);

	deleteNodes(root);
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
{
	preorder = &pre;
	postorder = &post;

	int preIndex = 0;
	int postIndex = 0;
	
	return construct(&preIndex, &postIndex);
}

TreeNode* construct(int* preIndex, int* postIndex)
{
	TreeNode* node = new TreeNode(preorder->operator[]((*preIndex)++));
	if (node->val != (*postorder)[*postIndex])
	{
		node->left = construct(preIndex, postIndex);
		if ((*postorder)[*postIndex] != node->val)
			node->right = construct(preIndex, postIndex);
		*postIndex += 1 * (*postIndex < postorder->size() && (*postorder)[*postIndex] == node->val);
	}
	else
		(*postIndex)++;

	return node;
}
*/