/*
#include<vector>
#include<unordered_map>

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

vector<TreeNode*> allPossibleFBT(int N);
vector<TreeNode*> getTrees(int N, unordered_map<int, vector<TreeNode*>>& cache);

void main()
{
	vector<TreeNode*> bt = allPossibleFBT(5);
}

vector<TreeNode*> allPossibleFBT(int N)
{
	if (N % 2 == 0) return vector<TreeNode*>();

	unordered_map<int, vector<TreeNode*>> cache;
	cache[0] = vector<TreeNode*>();
	cache[1] = vector<TreeNode*>();
	cache[1].push_back(new TreeNode());

	return getTrees(N, cache);
}

vector<TreeNode*> getTrees(int N, unordered_map<int, vector<TreeNode*>>& cache)
{
	unordered_map<int, vector<TreeNode*>>::iterator cacheResult;
	if ((cacheResult = cache.find(N)) != cache.end())
		return cacheResult->second;
	
	if (N % 2 == 0)
		cache[N] = vector<TreeNode*>();
	else
	{
		vector<TreeNode*> trees;
		for (int i = 0; i < N; ++i)
		{
			vector<TreeNode*> leftSubtrees = getTrees(i, cache);
			vector<TreeNode*> rightSubtrees = getTrees(N - 1 - i, cache);
			for (vector<TreeNode*>::iterator leftIterator = leftSubtrees.begin();
				leftIterator < leftSubtrees.end(); ++leftIterator)
			{
				for (vector<TreeNode*>::iterator rightIterator = rightSubtrees.begin();
					rightIterator < rightSubtrees.end(); ++rightIterator)
				{
					TreeNode* root = new TreeNode();
					root->left = *leftIterator;
					root->right = *rightIterator;

					trees.push_back(root);
				}
			}
		}
		cache[N] = trees;

		return trees;
	}
}
*/