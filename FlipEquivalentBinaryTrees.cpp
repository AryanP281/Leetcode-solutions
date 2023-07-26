
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

bool flipEquiv(TreeNode* root1, TreeNode* root2);
bool equivSubtree(TreeNode* node1, TreeNode* node2);

int main()
{
    /*TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(8);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(6);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(5);
    root2->right->right->left = new TreeNode(8);
    root2->right->right->right = new TreeNode(7);*/

    TreeNode* root1 = new TreeNode(0,nullptr,new TreeNode(1));
    TreeNode* root2 = new TreeNode(0, new TreeNode(1),nullptr);
    cout << flipEquiv(root1,root2);
    
    getchar();
    return 0;
}

bool flipEquiv(TreeNode* root1, TreeNode* root2) 
{
    equivSubtree(root1,root2);
}

bool equivSubtree(TreeNode* node1, TreeNode* node2)
{
    if(!node1)
        return (node2 == nullptr);
    else if(!node2)
        return false;

    if(node1->val != node2->val)
        return false;

    return (equivSubtree(node1->right, node2->right) && equivSubtree(node1->left, node2->left)) || 
    (equivSubtree(node1->right, node2->left) && equivSubtree(node1->left, node2->right));
}