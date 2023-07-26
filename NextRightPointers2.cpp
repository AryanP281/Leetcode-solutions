
#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root);
void traverseAndConnect(Node* currNode);

Node* generateTree(vector<int>& arr)
{
    if(arr.size() == 0)
        return nullptr;
    
    Node* root = new Node(arr[0]);

    queue<Node*> nodes;
    nodes.push(root);

    for(int i = 1; i < arr.size(); ++i)
    {
        Node* currNode = nodes.front();
        nodes.pop();

        if(arr[i++] != -1)
        {
            currNode->left = new Node(arr[i-1]);
            nodes.push(currNode->left);
        }
        if(arr[i] != -1)
        {
            currNode->right = new Node(arr[i]);
            nodes.push(currNode->right);
        }
    }

    return root;
}

int main()
{
    vector<int> vals = {1,2,3,4,5,-1,6,7,-1,-1,-1,-1,8};
    Node* root = generateTree(vals);
    connect(root);

    getchar();
    return 0;
}

Node* connect(Node* root) 
{
    Node* prevLevelStart = root; //The 1st node in the previous level

    while(prevLevelStart)
    {
        Node* currNode = prevLevelStart; //The previous level node whose children are currently being processed
        Node* currLevelStart = nullptr; //The 1st non-null node in the current level (to be used as prevLevelStart for next level)
        Node* prevNode = nullptr; //The rightmost processed node in the current level 

        while(currNode)
        {
            if(currNode->left)
            {
                if(prevNode)
                {
                    prevNode->next = currNode->left;
                    prevNode = prevNode->next;
                }
                else
                {
                    //currNode->left is the 1st non-null node in the current level
                    currLevelStart = currNode->left;
                    prevNode = currNode->left;
                }
            }
            if(currNode->right)
            {
                if(prevNode)
                {
                    prevNode->next = currNode->right;
                    prevNode = prevNode->next;
                }
                else
                {
                    //currNode->right is the 1st non-null node in the current level
                    currLevelStart = currNode->right;
                    prevNode = currNode->right;
                }
            }

            currNode = currNode->next; //Moving to the next node in the previous level
        }

        //Moving to the next level
        prevLevelStart = currLevelStart;
    }

    return root; 
}