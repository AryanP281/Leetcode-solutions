
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* generateTree(vector<int>& vals)
{
    TreeNode* root = new TreeNode(vals[0]);

    queue<TreeNode*>* prevLevel = new queue<TreeNode*>();
    queue<TreeNode*>* currLevel = new queue<TreeNode*>();

    prevLevel->push(root);
    int i = 1;
    while(!prevLevel->empty())
    {
        while(!prevLevel->empty())
        {
            if(i < vals.size() && vals[i] != -100)
            {
                prevLevel->front()->left = new TreeNode(vals[i]);
                currLevel->push(prevLevel->front()->left);
            }
            ++i;
            if(i < vals.size() && vals[i] != -100)
            {
                prevLevel->front()->right = new TreeNode(vals[i]);
                currLevel->push(prevLevel->front()->right);
            }
            ++i;

            prevLevel->pop();
        }
        delete prevLevel;
        prevLevel = currLevel;
        currLevel = new queue<TreeNode*>();
    }
    delete prevLevel;
    delete currLevel;

    return root;
}  

int pathSum(TreeNode* root, int targetSum);
void findPaths(TreeNode* currNode, int targetSum, int currSum, unordered_map<int,int>& cumSums, int* pathsCount);

int main()
{
    vector<int> vals = {5,4,8,11,-100,13,4,7,2,-100,-100,5,1};
    TreeNode* root = generateTree(vals);

    cout << pathSum(root, 22);

    getchar();
    return 0;
}

int pathSum(TreeNode* root, int targetSum) 
{
    unordered_map<int,int> cumSums;
    cumSums[0] = 1;
    int pathsCount = 0;

    findPaths(root, targetSum, 0, cumSums, &pathsCount);

    return pathsCount;
}

void findPaths(TreeNode* currNode, int targetSum, int currSum, unordered_map<int,int>& cumSums, int* pathsCount)
{
    if(!currNode)
        return;

    currSum += currNode->val;
    unordered_map<int,int>::iterator itr = cumSums.find(currSum - targetSum);
    if(itr != cumSums.end())
        *pathsCount += cumSums[currSum - targetSum];
    cumSums[currSum]++;

    findPaths(currNode->left, targetSum, currSum, cumSums, pathsCount);
    findPaths(currNode->right, targetSum, currSum, cumSums, pathsCount);

    itr = cumSums.find(currSum);
    itr->second--;
    if(!itr->second)
        cumSums.erase(itr);
}