#include <algorithm>
#include <vector>
#include <queue>

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
	vector<vector<int>> levelOrderBottom(TreeNode *root)
	{
		vector<vector<int>> ans;
		vector<int> level;

		if (root == nullptr)
			return ans;

		TreeNode *sign = root;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode *curr = q.front();
			int value = curr->val;
			q.pop();
			level.push_back(value);

			if (curr->left != nullptr)
				q.push(curr->left);
			if (curr->right != nullptr)
				q.push(curr->right);

			if (curr == sign)
			{
				ans.push_back(level);
				level.clear();
				sign = curr->right != nullptr ? curr->right : curr->left;
			}
		}
		if (!level.empty())
			ans.push_back(level);

		reverse(ans.begin(), ans.end());

		return ans;
	}
};