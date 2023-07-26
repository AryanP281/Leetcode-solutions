#pragma once

#include<unordered_map>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class AvlTree
{
private :
	std::unordered_map<TreeNode*, int> maxSubtreeSizes;

	TreeNode* insertIntoTree(int val, TreeNode* root);
	bool isBalanced(TreeNode* node);
	TreeNode* leftRotation(TreeNode* node);
	TreeNode* rightRotation(TreeNode* node);

public :
	TreeNode* root;

	AvlTree();
	~AvlTree();

	void insert(int val);

};
