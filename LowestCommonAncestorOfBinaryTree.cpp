
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
void findLca(TreeNode* curr, TreeNode** specialNodes, TreeNode** lca);

TreeNode* generateTree(vector<int>& array)
{
    TreeNode* root = new TreeNode(array[0]);

    queue<TreeNode*>* currLevel = new queue<TreeNode*>();
    currLevel->push(root);
    queue<TreeNode*>* nextLevel = new queue<TreeNode*>();

    int i = 1;
    while(!currLevel->empty())
    {
        while(!currLevel->empty())
        {
            TreeNode* curr = currLevel->front();
            currLevel->pop();

            if(i >= array.size())
                continue;
            else
            {
                if(array[i] > -1001)
                {
                    curr->left = new TreeNode(array[i]);
                    nextLevel->push(curr->left);
                }
                i++;
                if(i <= array.size() && array[i] > -1001)
                {
                    curr->right = new TreeNode(array[i]);
                    nextLevel->push(curr->right);
                }
                i++;
            }
        }

        delete currLevel;
        currLevel = nextLevel;
        nextLevel = new queue<TreeNode*>(); 
    }
    delete currLevel;
    delete nextLevel;

    return root;
}

TreeNode* findNode(TreeNode* curr, int val)
{
    if(!curr)
        return nullptr;

    if(curr->val == val)
        return curr;

    TreeNode* node = findNode(curr->left, val);
    if(!node)
        node = findNode(curr->right, val);

    return node;
}

int main()
{
    vector<int> arr = {3,1,4,-1001,2};
    TreeNode* root = generateTree(arr);

    TreeNode* lca = lowestCommonAncestor(root, findNode(root, 2), findNode(root, 3));
    cout << lca->val;

    getchar();
    return 0;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    TreeNode* nodes[2] = {p, q};
    TreeNode* lca = nullptr;

    findLca(root, nodes, &lca);

    return lca;
}

void findLca(TreeNode* curr, TreeNode** specialNodes, TreeNode** lca)
{
    if(!curr)
        return;

    if(specialNodes[0]->val < curr->val && specialNodes[1]->val < curr->val)
        findLca(curr->left, specialNodes, lca);
    else if(specialNodes[0]->val > curr->val && specialNodes[1]->val > curr->val)
        findLca(curr->right, specialNodes, lca);

    if(*lca == nullptr)
        *lca = curr;    
}