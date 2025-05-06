
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

typedef pair<TreeNode*,TreeNode*> Pair;

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

void recoverTree(TreeNode* root);
Pair findPairToSwitch(TreeNode* currNode, Pair& switchPair);

int main()
{
    vector<int> flatVals = {3,1,4,-1,-1,2,-1,-1,-1};
    TreeNode* root = generateTree(flatVals);

    recoverTree(root);

    getchar();
    return 0;
}

void recoverTree(TreeNode* root) 
{
    Pair switchPair(nullptr, nullptr);

    findPairToSwitch(root, switchPair);

    if(switchPair.first != nullptr)
    {
        int temp = switchPair.first->val;
        switchPair.first->val = switchPair.second->val;
        switchPair.second->val = temp;
    }
}

Pair findPairToSwitch(TreeNode* currNode, Pair& switchPair)
{
    Pair leftResults = currNode->left ? findPairToSwitch(currNode->left, switchPair) : Pair(currNode, currNode);
    Pair rightResults = currNode->right ? findPairToSwitch(currNode->right, switchPair) : Pair(currNode, currNode);

    if(leftResults.second->val > currNode->val && rightResults.first->val < currNode->val)
    {
        switchPair = Pair(rightResults.first, leftResults.second);
        return Pair(rightResults.first, leftResults.second);
    }
    else if(leftResults.second->val > currNode->val)
    {
        switchPair = Pair(currNode, leftResults.second);

        return Pair(leftResults.first->val < currNode->val ? leftResults.first : currNode, rightResults.second->val > leftResults.second->val ? rightResults.second : leftResults.second);
    }
    else if(rightResults.first->val < currNode->val)
    {
        switchPair = Pair(rightResults.first, currNode);

        return Pair(leftResults.first->val < rightResults.first->val ? leftResults.first : rightResults.first, rightResults.second->val > currNode->val ? rightResults.second : currNode);
    }

    return Pair(leftResults.first, rightResults.second);
}