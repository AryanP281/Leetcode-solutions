/*
#include <iostream>
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
    if (node->left) deleteNodes(node->left);
    if (node->right) deleteNodes(node->right);

    delete node;
}

int pseudoPalindromicPaths(TreeNode* root);
void getPaths(TreeNode* node, vector<int>& digitFreqs, int oddParities, int* palindromicCount);

void main()
{
    TreeNode* root = new TreeNode(2, new TreeNode(1, new TreeNode(1), new TreeNode(3, nullptr, new TreeNode(1))),
        new TreeNode(1));

    cout << pseudoPalindromicPaths(root);

    deleteNodes(root);
}

int pseudoPalindromicPaths(TreeNode* root)
{
    vector<int> digitFreqs(9, 0);
    int palindromicCount = 0;
    getPaths(root, digitFreqs, 0, &palindromicCount);

    return palindromicCount;
}

void getPaths(TreeNode* node, vector<int>& digitFreqs, int oddParities, int* palindromicCount)
{
    digitFreqs[node->val - 1]++;
    if (digitFreqs[node->val - 1] % 2 == 0)
        oddParities--;
    else
        oddParities++;
    
    if (!node->left && !node->right)
        *palindromicCount += (oddParities <= 1);
    else
    {
        if(node->left) getPaths(node->left, digitFreqs, oddParities, palindromicCount);
        if(node->right) getPaths(node->right, digitFreqs, oddParities,palindromicCount);
    }

    digitFreqs[node->val - 1]--;
}
*/