/*
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

int maxLevelSum(TreeNode* root);
TreeNode generateTree(TreeNode* nodes, int count);

void main()
{
    
    TreeNode nodes[5] = { TreeNode(989), TreeNode(10250), TreeNode(98693), TreeNode(-89388),
    TreeNode(-32127) };

    nodes[0].left = nullptr;
    nodes[0].right = nodes+1;
    nodes[1].left = nodes + 2;
    nodes[1].right = nodes + 3;
    nodes[2].left = nodes[2].right = nullptr;
    nodes[3].left = nullptr;
    nodes[3].right = nodes + 4;

    cout << maxLevelSum(nodes);
    
}

int maxLevelSum(TreeNode* root)
{
    int maxLevel[2] = { INT_MIN, 0 };

    queue<TreeNode*> queue1, queue2;
    queue<TreeNode*>* currentLevelQueue = &queue1;
    queue<TreeNode*>* nextLevelQueue = &queue2;

    nextLevelQueue->push(root);

    int levelSum = 0;
    int currentLevel = 0;
    do
    {
        ++currentLevel;
        levelSum = 0;

        queue<TreeNode*>* temp = currentLevelQueue;
        currentLevelQueue = nextLevelQueue;
        nextLevelQueue = temp;

        while (!currentLevelQueue->empty())
        {

            TreeNode* node = currentLevelQueue->front();
            currentLevelQueue->pop();
            levelSum += node->val;

            if (node->left != nullptr) nextLevelQueue->push(node->left);
            if (node->right != nullptr) nextLevelQueue->push(node->right);
        }

        if (levelSum > maxLevel[0])
        {
            maxLevel[0] = levelSum;
            maxLevel[1] = currentLevel;
        }
    } while (!nextLevelQueue->empty());

    return maxLevel[1];
}*/