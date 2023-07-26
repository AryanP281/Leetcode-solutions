/*
#include<iostream>
#include<string>
#include<vector>
#include<queue>

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

TreeNode* recoverFromPreorder(string S);
void parse(string& str, vector<int>& depths, vector<int>& vals);
TreeNode* constructTree(int* index, int prevDepth, vector<int>& vals, vector<int>& depths);

void main()
{
	string str = "1-401--349---90--88";

	TreeNode* root = recoverFromPreorder(str);

	queue<TreeNode*> nodesQueue;
	nodesQueue.push(root);
	while (!nodesQueue.empty())
	{
		if (nodesQueue.front()->left) nodesQueue.push(nodesQueue.front()->left);
		if (nodesQueue.front()->right) nodesQueue.push(nodesQueue.front()->right);

		TreeNode** nodeAddr = &nodesQueue.front();
		nodesQueue.pop();
		delete* nodeAddr;
	}
}

TreeNode* recoverFromPreorder(string S)
{
	vector<int> depths;
	vector<int> vals;
	parse(S, depths, vals);

	int i = 0;
	return constructTree(&i, -1, vals, depths);
}

void parse(string& str, vector<int>& depths, vector<int>& vals)
{
	depths.push_back(0);
	int depth = 0;
	int valStartIndex = -1;
	for (int a = 0; a < str.size(); ++a)
	{
		if (str[a] != '-')
		{
			if (depth != 0)
			{
				depths.push_back(depth);
				depth = 0;
			}
			valStartIndex = a*(valStartIndex == -1) + valStartIndex*(valStartIndex != -1);
		}
		else
		{
			if (valStartIndex != -1)
			{
				vals.push_back(stoi(string(str.begin() + valStartIndex, str.begin() + a)));
				valStartIndex = -1;
			}
			++depth;
		}
	}
	vals.push_back(stoi(string(str.begin() + valStartIndex, str.end())));

}

TreeNode* constructTree(int* index, int prevDepth, vector<int>& vals, vector<int>& depths)
{
	if (*index == vals.size() || (*index != 0 && depths[*index] - prevDepth != 1)) 
		return nullptr;

	int nodeDepth = depths[*index];
	TreeNode* node = new TreeNode(vals[(*index)++]);
	node->left = constructTree(index, nodeDepth, vals, depths);
	node->right = constructTree(index, nodeDepth, vals, depths);

	return node;
}
*/