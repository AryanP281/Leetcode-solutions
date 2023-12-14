
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

int maxPathSum(TreeNode* root);
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

int dfsForSolution(TreeNode* curr, int* maxSum);

int main()
{
    vector<int> arr = {2,-1,-2};

    TreeNode* root = generateTree(arr);

    cout << maxPathSum(root);

    getchar();
    return 0;
}

int maxPathSum(TreeNode* root) 
{
    int maxSum = -1000;

    maxSum = max(maxSum, dfsForSolution(root, &maxSum));

    return maxSum;
}

int dfsForSolution(TreeNode* curr, int* maxSum)
{
    if(!curr)
        return 0;

    int leftMaxSum = dfsForSolution(curr->left, maxSum);
    int rightMaxSum = dfsForSolution(curr->right, maxSum);
    *maxSum = max(*maxSum, max(leftMaxSum+curr->val, max(rightMaxSum+curr->val, max(curr->val,leftMaxSum+curr->val+rightMaxSum))));

    return max(curr->val, max(rightMaxSum+curr->val, leftMaxSum+curr->val));
}