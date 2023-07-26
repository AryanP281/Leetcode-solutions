
#include<bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef pair<bool,bool> Vec;

TreeNode* generateTree(vector<int>& arr)
{
    if(arr.size() == 0)
        return nullptr;
    
    TreeNode* root = new TreeNode(arr[0]);

    queue<TreeNode*> nodes;
    nodes.push(root);

    for(int i = 1; i < arr.size(); ++i)
    {
        TreeNode* currNode = nodes.front();
        nodes.pop();

        if(arr[i++] != -1)
        {
            currNode->left = new TreeNode(arr[i-1]);
            nodes.push(currNode->left);
        }
        if(arr[i] != -1)
        {
            currNode->right = new TreeNode(arr[i]);
            nodes.push(currNode->right);
        }
    }

    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
Vec traverse(TreeNode* node, int pVal, int qVal, TreeNode** ancestor);

int main()
{

    vector<int> vals = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root = generateTree(vals);
    TreeNode* ancestor = lowestCommonAncestor(root, root->left, root->right);
    cout << ancestor->val;

    getchar();
    return 0;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    TreeNode* ancestor = nullptr;

    traverse(root, p->val, q->val, &ancestor);

    return ancestor;   
}

Vec traverse(TreeNode* node, int pVal, int qVal, TreeNode** ancestor)
{
    if(!node)
        return Vec(false, false);

    Vec leftResult = traverse(node->left, pVal, qVal, ancestor);
    Vec rightResult(false,false);
    if(!(*ancestor))
    {
        rightResult = traverse(node->right, pVal, qVal, ancestor);
        if(!(*ancestor))
        {
            if((leftResult.first || rightResult.first || node->val == pVal) && 
            (leftResult.second || rightResult.second || node->val == qVal))
                *ancestor = node;
        }
    }

    return Vec(leftResult.first || rightResult.first || node->val == pVal, 
    leftResult.second || rightResult.second || node->val == qVal);
}