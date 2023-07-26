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

TreeNode* bstFromPreorder(vector<int>& preorder);
TreeNode* constructTree(vector<int>& preorder, int* currentNode, int min, int max);
bool inRange(int x, int min, int max);

void main()
{
    int arr[] = { 1,2,3 };
    vector<int> preorder(arr, arr + 3);

    TreeNode* root = bstFromPreorder(preorder);
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    int currentNode = 0;
    return constructTree(preorder, &currentNode, INT_MIN, INT_MAX);
}

TreeNode* constructTree(vector<int>& preorder, int* currentNode, int min, int max)
{
    if (*currentNode == preorder.size() || !inRange(preorder[*currentNode], min, max))
        return nullptr;

    TreeNode* node = new TreeNode(preorder[(*currentNode)++]);

    node->left = constructTree(preorder, currentNode, min, node->val);
    node->right = constructTree(preorder, currentNode, node->val + 1, max);

    return node;
}

bool inRange(int x, int min, int max)
{
    return x >= min && x < max;
}
*/