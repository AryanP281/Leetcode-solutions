
#include<bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode* root);
int* checkValidity(TreeNode* currNode);

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
    vector<int> arr = {5,1,4,-1001,-1001,3,6};
    TreeNode* root = generateTree(arr);
    cout << isValidBST(root);

    getchar();
    return 0;
}

bool isValidBST(TreeNode* root) 
{
    int* res = checkValidity(root);
    bool isValid = res[0];
    delete[] res;
    return isValid;
}

int* checkValidity(TreeNode* currNode)
{
    
    int* res = new int[3];
    res[0] = 1;
    res[1] = currNode->val;
    res[2] = currNode->val;

    if(currNode->left)
    {
        int* leftRes = checkValidity(currNode->left);
        res[0] &= 1*(leftRes[0] && leftRes[2] < currNode->val);
        res[1] = min(res[1], leftRes[1]);
        res[2] = max(res[2], leftRes[2]);
        delete[] leftRes;
    }
    if(res[0] && currNode->right)
    {
        int* rightRes = checkValidity(currNode->right);
        res[0] &= 1*(rightRes[0] && rightRes[1] > currNode->val);
        res[1] = min(res[1], rightRes[1]);
        res[2] = max(res[2], rightRes[2]);
        delete[] rightRes;
    }

    return res;
}