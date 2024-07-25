
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

bool isSameTree(TreeNode* p, TreeNode* q);

int main()
{
    vector<int> n1 = {1,2,1};
    vector<int> n2 = {1,1,2};

    TreeNode* p = generateTree(n1);
    TreeNode* q = generateTree(n2);

    cout << isSameTree(p,q);

    getchar();
    return 0;
}

bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(!p && !q)
        return true;
    else if(!p || !q)
        return false;
    
    queue<TreeNode*>** pBfsQueues = new queue<TreeNode*>*[2];
    pBfsQueues[0] = new queue<TreeNode*>();
    pBfsQueues[1] = new queue<TreeNode*>();
    queue<TreeNode*>** qBfsQueues = new queue<TreeNode*>*[2];
    qBfsQueues[0] = new queue<TreeNode*>();
    qBfsQueues[1] = new queue<TreeNode*>();

    pBfsQueues[0]->push(p);
    qBfsQueues[0]->push(q);

    while(!pBfsQueues[0]->empty() || !qBfsQueues[0]->empty())
    {
        if(pBfsQueues[0]->empty() || qBfsQueues[0]->empty() || pBfsQueues[0]->size() != qBfsQueues[0]->size())
            return false;
        
        while(!pBfsQueues[0]->empty())
        {
            TreeNode* pNode = pBfsQueues[0]->front();
            pBfsQueues[0]->pop();
            TreeNode* qNode = qBfsQueues[0]->front();
            qBfsQueues[0]->pop();

            if((pNode->val != qNode->val) || (pNode->left && !qNode->left) || (!pNode->left && qNode->left) || (pNode->right && !qNode->right) || (!pNode->right && qNode->right))
                return false;

            if(pNode->left)
            {
                pBfsQueues[1]->push(pNode->left);
                qBfsQueues[1]->push(qNode->left);
            }   
            if(pNode->right)
            {
                pBfsQueues[1]->push(pNode->right);
                qBfsQueues[1]->push(qNode->right);
            }        
            
        }

        delete pBfsQueues[0];
        pBfsQueues[0] = pBfsQueues[1];
        pBfsQueues[1] = new queue<TreeNode*>();

        delete qBfsQueues[0];
        qBfsQueues[0] = qBfsQueues[1];
        qBfsQueues[1] = new queue<TreeNode*>();
    }

    delete pBfsQueues[0];
    delete pBfsQueues[1];
    delete[] pBfsQueues;  

    delete qBfsQueues[0];
    delete qBfsQueues[1];
    delete[] qBfsQueues; 

    return true;    
}

