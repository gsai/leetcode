#include <vector>

using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

class Solution
{
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum)
	{
		vector<vector<int> > ans;
		vector<int> p;
		if (root == nullptr)
			return ans;

		genenrate(root, ans, p, sum);
		return ans;
	}
private:
	void genenrate(TreeNode *root, vector<vector<int> > &lines, vector<int> path, int n)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			if (root->val == n)
			{
				path.push_back(n);
				lines.push_back(path);
			}
			return;
		}
			path.push_back(root->val);
			if (root->left != nullptr)
				genenrate(root->left, lines, path, n - root->val);
			if (root->right != nullptr)
				genenrate(root->right, lines, path, n - root->val);

	}
};