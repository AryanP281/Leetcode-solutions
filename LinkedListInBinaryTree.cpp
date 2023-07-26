
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

bool isSubPath(ListNode* head, TreeNode* root);
bool dfs(TreeNode* currTreeNode, ListNode* currListNode, ListNode* head);

int main()
{
    vector<int> listVals = {1,1,1,3,1,1,1,1,1,3};
    ListNode* head = new ListNode(listVals[0]);
    ListNode* curr = head;
    for(int i = 1; i < listVals.size(); ++i, curr = curr->next)
    {
        curr->next = new ListNode(listVals[i]);
    }

    vector<int> treeVals = {1,4,4,-1,2,2,-1,1,-1,6,8,-1,-1,-1,-1,1,3};
    TreeNode* root = generateTree(treeVals);

    cout << (isSubPath(head, root) ? "True" : "False");

    getchar();
    return 0;
}

bool isSubPath(ListNode* head, TreeNode* root) 
{
    vector<int> lst;
    for(ListNode* curr = head; curr; curr = curr->next)
    {
        lst.push_back(curr->val);
    }
    
    vector<int> lps(lst.size(), 0);
    int i = 0;
    int j = 1;
    while(j < lst.size())
    {
        if(lst[j] == lst[i])
        {
            lps[j] = i+1;
            ++i;
            ++j;
        }
        else
        {
            if(i != 0)
                i = lps[i-1];
            else
            {
                lps[j] = 0;
                j++;
            }
        }
    }
    
    return dfs(root, head, head);
}

bool dfs(TreeNode* currNode, vector<int>& lst, vector<int>& lps, int i)
{
    if(!currNode)
        return false;

    if(currNode->val == lst[i])
    {
        if(i == lst.size() - 1)
            return true;
        
        return dfs(currNode->left, lst, lps, i+1) || dfs(currNode->right, lst, lps, i+1);
    }

    bool res = false;
    while(lps[i])
    {
        res = dfs(currNode->left, lst, lps, lps[i]) || dfs(currNode->right, lst, lps, lps[i]);
        if(res)
            return true;
        i = lps[i]; 
    }

    return dfs(currNode->left, lst, lps, 0) || dfs(currNode->right, lst, lps, 0);
}

/*bool dfs(TreeNode* currTreeNode, ListNode* currListNode, ListNode* head)
{
    if(!currTreeNode)
        return false;

    if(currTreeNode->val != currListNode->val)
        currListNode = head;

    if(currTreeNode->val == currListNode->val)
    {
        if(!currListNode->next)
            return true;
        
        return dfs(currTreeNode->left, currListNode->next, head) || dfs(currTreeNode->right, currListNode->next, head);
    }

    return dfs(currTreeNode->left, head, head) || dfs(currTreeNode->right, head, head);
}*/