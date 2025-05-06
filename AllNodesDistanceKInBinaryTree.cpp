
#include<bits/stdc++.h>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main()
{

    getchar();

    return 0;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{
    vector<int> result; 
    
    getDistanceKNodes(root, target, -1, k, result);

    return result;
}

int getDistanceKNodes(TreeNode* currNode, TreeNode* target, int parentDistance, int k, vector<int>& results)
{
    if(!currNode)
        return -1;

    int currDistance = (currNode == target) ? 0 : (parentDistance == -1) ? -1 : parentDistance+1;

    if(currDistance == -1)
    {
        int lcDistance = getDistanceKNodes(currNode->left, target, -1, k, results);
        if(lcDistance != -1)
            currDistance = lcDistance+1;
        int rcDistance = getDistanceKNodes(currNode->right, target, currDistance, k, results);
        if(lcDistance == -1 && rcDistance != -1)
        {
            currDistance = rcDistance+1;
            lcDistance = getDistanceKNodes(currNode->left, target, currDistance, k, results);
        }
    }
    else
    {
        getDistanceKNodes(currNode->left, target, parentDistance+1, k, results);
        getDistanceKNodes(currNode->right, target, parentDistance+1, k, results);
    }

    if(currDistance == k)
        results.push_back(currNode->val);

    return currDistance;
}