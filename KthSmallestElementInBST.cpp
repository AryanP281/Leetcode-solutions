
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

int kthSmallest(TreeNode* root, int k);
void getKth(TreeNode* currNode, TreeNode** res, int k, int* currK);

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

int main()
{
    vector<int> vals = {5,3,6,2,4,-1001,-1001,1};
    TreeNode* root = generateTree(vals);

    cout << kthSmallest(root, 3);

    getchar();
    
    return 0;
}

int kthSmallest(TreeNode* root, int k) 
{
    TreeNode* res = nullptr;
    int currK = 0;

    getKth(root, &res, k, &currK);

    return res->val;
}

void getKth(TreeNode* currNode, TreeNode** res, int k, int* currK)
{
    if(!currNode)
        return;

    getKth(currNode->left, res, k, currK);
    
    (*currK)++;
    if(*currK == k)
        *res = currNode;

    getKth(currNode->right, res, k, currK);
}