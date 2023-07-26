/*
#include<iostream>
#include<vector>

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

TreeNode* constructMaximumBinaryTree(vector<int>& nums);
TreeNode* constructTree(vector<int> arr, int l, int r);
int* getMax(vector<int>& arr, int l, int r);

void main() 
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(5);
    
    TreeNode* root = constructMaximumBinaryTree(nums);

    cout << root->val;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
    return constructTree(nums, 0, nums.size() - 1);
}

TreeNode* constructTree(vector<int> arr, int l, int r)
{
    if (l == r)
    {
        TreeNode* leaf = new TreeNode;
        leaf->val = arr[l];
        return leaf;
    }
    else if (l > r) return nullptr;

    int* maxNode = getMax(arr, l, r);
    arr.erase(arr.begin() + maxNode[1]);

    TreeNode* root = new TreeNode;
    root->val = maxNode[0];

    delete[] maxNode;

    int m = (r - l - 1) / 2;
    root->left = constructTree(arr, l, l + m);
    root->right = constructTree(arr, l + m + 1, r - 1);

    return root;
}

int* getMax(vector<int>& arr, int l, int r)
{
    int* max = new int[2];
    max[0] = arr[l];
    max[1] = l;

    for (int a = l + 1; a < r + 1; ++a)
    {
        if (arr[a] > max[0])
        {
            max[0] = arr[a];
            max[1] = a;
        }
    }

    return max;
}
*/