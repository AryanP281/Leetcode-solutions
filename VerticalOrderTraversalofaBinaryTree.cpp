/*
#include<iostream>
#include<vector>
#include <map>
#include <algorithm>

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

struct Vec2D
{
	int x;
	int y;

	Vec2D() : x(0), y(0) {}
	Vec2D(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

int maxY;

vector<vector<int>> verticalTraversal(TreeNode* root);
void traverse(TreeNode* node, map<int, vector<pair<TreeNode*, int>>>& xCoords, Vec2D coords);
vector<int> countSort(vector<pair<TreeNode*, int>>& arr);
bool cmp(pair<TreeNode*, int>& i, pair<TreeNode*, int>& j)
{
    if (i.second == j.second) return i.first->val < j.first->val;

    return i.second > j.second;
}

void main()
{
    /*TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20));
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    TreeNode* nodes[17] = { new TreeNode(0), new TreeNode(2), new TreeNode(1), new TreeNode(3),
      nullptr, nullptr, nullptr, new TreeNode(4), new TreeNode(5), nullptr, new TreeNode(7),
    new TreeNode(6), nullptr, new TreeNode(10), new TreeNode(8), new TreeNode(11), new TreeNode(9)
    };
    
    int i = 1;
    for (int a = 0; a < 15 && i < 17; ++a)
    {
        if (nodes[a] == nullptr) continue;

        nodes[a]->left = nodes[i++];
        nodes[a]->right = nodes[i++];
    }

       
    vector<vector<int>> ct = verticalTraversal(nodes[0]);
}

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    maxY = 0;
    map<int, vector<pair<TreeNode*, int>>> xCoords;
    traverse(root, xCoords, Vec2D(0, 0));

    vector<vector<int>> verticalNodes;
    for (map<int, vector<pair<TreeNode*,int>>>::iterator itr = xCoords.begin(); itr != xCoords.end(); ++itr)
    {
        //sort(itr->second.begin(), itr->second.end(), cmp);
        verticalNodes.push_back(countSort(itr->second));
        /*for (int a = 0; a < itr->second.size(); ++a)
        {
            (verticalNodes.end() - 1)->push_back(itr->second[a].first->val);
        }
    }

    return verticalNodes;
}

void traverse(TreeNode* node, map<int, vector<pair<TreeNode*, int>>>& xCoords, Vec2D coords)
{
    if (node == nullptr) return;

    map<int, vector<pair<TreeNode*, int>>>::iterator itr = xCoords.find(coords.x);
    if (itr == xCoords.end())
    {
        vector<pair<TreeNode*, int>> nodes;
        nodes.push_back(pair<TreeNode*, int>(node, coords.y));
        xCoords[coords.x] = nodes;
    }
    else
        itr->second.push_back(pair<TreeNode*, int>(node, coords.y));

    traverse(node->left, xCoords, Vec2D(coords.x - 1, coords.y - 1));
    traverse(node->right, xCoords, Vec2D(coords.x + 1, coords.y - 1));
    maxY = max(maxY, -1 * coords.y);
}

vector<int> countSort(vector<pair<TreeNode*, int>>& arr)
{
    vector<TreeNode*>* counts = new vector<TreeNode*>[maxY + 1];
    for (int a = 0; a < arr.size(); ++a)
    {
        counts[arr[a].second * -1].push_back(arr[a].first);
    }

    vector<int> sortedVals;
    for (int a = 0; a < maxY+1;++a)
    {
        for (int b = 0; b < counts[a].size(); ++b)
        {
            sortedVals.push_back(counts[a][b]->val);
        }
    }

    return sortedVals;
}*/