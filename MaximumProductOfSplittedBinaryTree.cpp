
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

int maxProduct(TreeNode* root);
int64_t getSubtreeSum(TreeNode* currNode);
int64_t findMaxSplitProduct(TreeNode* currNode, int64_t& rootSum, int64_t* maxProd);

int main()
{
    vector<int> vals = {1,-1,2,3,4,-1,-1,5,6};
    TreeNode* root = generateTree(vals);

    cout << maxProduct(root);

    getchar();
    return 0;
}

int maxProduct(TreeNode* root) 
{
    int64_t rootSum = getSubtreeSum(root);
    int64_t maxSplitProduct = 0;

    findMaxSplitProduct(root, rootSum, &maxSplitProduct);

    return (maxSplitProduct % ((int)1e9 + 7));
}

int64_t getSubtreeSum(TreeNode* currNode)
{
    if(!currNode)
        return 0;

    int64_t sum = getSubtreeSum(currNode->left) + getSubtreeSum(currNode->right) + currNode->val;

    return sum;
}

int64_t findMaxSplitProduct(TreeNode* currNode, int64_t& rootSum, int64_t* maxProd)
{
    if(!currNode)
        return 0;

    int leftSum = findMaxSplitProduct(currNode->left, rootSum, maxProd);
    int rightSum = findMaxSplitProduct(currNode->right, rootSum, maxProd);

    *maxProd = max(*maxProd, max(leftSum*(rootSum-leftSum), rightSum*(rootSum-rightSum)));

    return leftSum + rightSum + currNode->val;
}