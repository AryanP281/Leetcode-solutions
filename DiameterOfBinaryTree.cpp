
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
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

int diameterOfBinaryTree(TreeNode* root) 
{
    int diameter = 0;

    findMaxLen(root, &diameter);

    return diameter;
}

int findMaxLen(TreeNode* curr, int* diam)
{
    if(!curr)
        return 0;

    int leftLen = findMaxLen(curr->left,diam);
    int rightLen = findMaxLen(curr->right, diam);

    *diam = max(*diam, leftLen+rightLen);

    return max(leftLen,rightLen)+1;
}
