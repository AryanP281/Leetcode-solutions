
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec 
{
private:
    vector<string>* getTokens(string& str)
    {
        vector<string>* tokens = new vector<string>();

        string currToken = "";
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ',')
            {
                tokens->push_back(currToken);
                currToken = "";
            }
            else
                currToken += str[i];
        }
        tokens->push_back(currToken);

        return tokens;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string encodedTree = "";
        queue<TreeNode*>* currLevel = new queue<TreeNode*>();
        queue<TreeNode*>* nextLevel = new queue<TreeNode*>();

        currLevel->push(root);
        while(!currLevel->empty())
        {
            while(!currLevel->empty())
            {
                TreeNode* currNode = currLevel->front();
                currLevel->pop();
                if(currNode == NULL)
                {
                    encodedTree += "null,";
                    continue;
                }

                encodedTree += to_string(currNode->val) + ",";
                nextLevel->push(currNode->left);
                nextLevel->push(currNode->right);
            }

            delete currLevel;
            currLevel = nextLevel;
            nextLevel = new queue<TreeNode*>();
        }

        delete currLevel;
        delete nextLevel;

        encodedTree.pop_back();

        return encodedTree;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string>* tokens = this->getTokens(data);
        if(tokens->at(0) == "null")
            return NULL;

        queue<TreeNode*>* currLevel = new queue<TreeNode*>();
        queue<TreeNode*>* nextLevel = new queue<TreeNode*>();

        TreeNode* root = new TreeNode(stoi(tokens->at(0)));
        currLevel->push(root);
        int i = 1;

        while(!currLevel->empty())
        {
            while(!currLevel->empty())
            {
                TreeNode* currNode = currLevel->front();
                currLevel->pop();

                if(tokens->at(i) != "null")
                {
                    currNode->left = new TreeNode(stoi(tokens->at(i)));
                    nextLevel->push(currNode->left);
                }
                i++;
                if(tokens->at(i) != "null")
                {
                    currNode->right = new TreeNode(stoi(tokens->at(i)));
                    nextLevel->push(currNode->right);
                }
                i++;
            }

            delete currLevel;
            currLevel = nextLevel;
            nextLevel = new queue<TreeNode*>();
        }

        delete currLevel;
        delete nextLevel;

        return root;
    }
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

int main()
{

    vector<int> arr = {1,2,3,-1001,-1001,4,5};
    TreeNode* root = generateTree(arr);

    Codec cdc;
    string serialized = cdc.serialize(root);
    cdc.deserialize(serialized);

    getchar();
    return 0;
}
