
#include<bits/stdc++.h>

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

int main()
{

    getchar();
    return 0;
}

int kthSmallest(TreeNode* root, int k) 
{
    int nodePos = 0;
    int kthVal = -1;
    inorderTraversel(root, k, &nodePos, &kthVal);

    return kthVal;
}

void inorderTraversel(TreeNode* node, int k, int* nodePos, int* kthVal)
{
   if(!node) return;

   inorderTraversel(node->left, k, nodePos, kthVal);
   if(*kthVal == -1)
   {
        if(++(*nodePos) == k) 
        {
            *kthVal = node->val;
            return;
        }
        inorderTraversel(node->right,k,nodePos,kthVal);
   }
}