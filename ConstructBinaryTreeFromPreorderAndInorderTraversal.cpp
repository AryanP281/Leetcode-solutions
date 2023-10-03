
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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
TreeNode* construct(int l, int r, vector<int>& pre, vector<int>& in, int* i);

int main()
{
    vector<int> pre = {1,2,3,4,5,7,6,8};
    vector<int> in = {2,3,1,7,5,4,6,8};

    TreeNode* root = buildTree(pre,in);

    getchar();
    return 0;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    int i = 0;
    return construct(0,preorder.size()-1,preorder,inorder,&i);
}

TreeNode* construct(int l, int r, vector<int>& pre, vector<int>& in, int* i)
{
    if(l == r)
        return new TreeNode(pre[(*i)++]);
    else if(l > r)
        return nullptr;

    TreeNode* currNode = new TreeNode(pre[(*i)++]);
    for(int j = l; j <= r; ++j)
    {
        if(in[j] == currNode->val)
        {
            currNode->left = construct(l,j-1,pre,in,i);
            currNode->right = construct(j+1,r,pre,in,i);
            break;
        }
    }

    return currNode;
}