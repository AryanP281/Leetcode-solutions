
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

bool isBalanced(TreeNode* root);
int checkBalance(TreeNode* currNode, bool* balanced);

int main()
{


    getchar();
    return 0;
}

bool isBalanced(TreeNode* root) 
{
    bool balanced = true;
    checkBalance(root, &balanced);

    return balanced;        
}

int checkBalance(TreeNode* currNode, bool* balanced)
{
    if(!currNode)
        return 0;

    int lh = checkBalance(currNode->left, balanced);
    int rh = checkBalance(currNode->right, balanced);

    *balanced &= (abs(lh - rh) <= 1);

    return 1 + max(lh,rh); 
}