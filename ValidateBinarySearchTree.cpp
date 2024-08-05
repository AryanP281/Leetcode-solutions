
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

struct Resp
{
    bool isV;
    int minVal;
    int maxVal;

    Resp(bool isV, int minV, int maxV)
    {
        this->isV = isV;
        this->minVal = minV;
        this->maxVal = maxV;
    }

    Resp() {}
};

int main()
{


    getchar();
    return 0;
}

bool isValidBST(TreeNode* root) 
{
    return check(root).isV;
}

Resp check(TreeNode* currNode)
{
    
    Resp resp(true, currNode->val, currNode->val);
    Resp childResp;
    if(currNode->left)
    {
        childResp = check(currNode->left);
        resp.isV &= (childResp.isV && childResp.maxVal < currNode->val);
        resp.minVal = min(childResp.minVal, resp.minVal);
        resp.maxVal = max(childResp.maxVal, resp.maxVal);
    }
    if(resp.isV && currNode->right)
    {
        childResp = check(currNode->right);
        resp.isV &= (childResp.isV && childResp.minVal > currNode->val);
        resp.minVal = min(childResp.minVal, resp.minVal);
        resp.maxVal = max(childResp.maxVal, resp.maxVal);
    }

    return resp;
}