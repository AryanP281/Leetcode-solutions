
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

vector<int> inorderTraversal(TreeNode* root);

int main()
{
    

    getchar();
    return 0;
}

vector<int> inorderTraversal(TreeNode* root) 
{
    if(!root)
        return {};
    
    typedef pair<TreeNode*,bool> Vec;

    stack<Vec> nodes;
    nodes.push(Vec(root,false));

    vector<int> inorder;
    while(!nodes.empty())
    {
        if(!nodes.top().second)
        {
            nodes.top().second = true;
            if(nodes.top().first->left)
                nodes.push(Vec(nodes.top().first->left, false));
        }
        else
        {
            Vec node = nodes.top();
            nodes.pop();
            if(node.first->right)
                nodes.push(Vec(node.first->right,false));
            
            inorder.push_back(node.first->val);
        }
        
    }

    return inorder;
}