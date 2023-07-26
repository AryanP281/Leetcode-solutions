
#include<bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main()
{

    getchar();
    return 0;
}

bool isBalanced(TreeNode* root) 
{
    bool isBalanced = true;
    getHeight(root, &isBalanced);

    return isBalanced;
}

int getHeight(TreeNode* node, bool* isBalanced)
{
    if(!node)
        return 0;

    int leftHeight = getHeight(node->left, isBalanced);
    int rightHeight = 0;
    if(*isBalanced)
    {
        rightHeight = getHeight(node->right, isBalanced);
        if(*isBalanced)
            *isBalanced = (abs(leftHeight - rightHeight) > 1) ? false : true;
    }

    return max(leftHeight, rightHeight) + 1;
}