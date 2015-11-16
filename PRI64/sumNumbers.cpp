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
	int sumNumbers(TreeNode *root)
	{
		return sumHelp(root, 0);
	}
private:
	int sumHelp(TreeNode *root, int curr)
	{
		if (root == nullptr)
			return curr;
		curr = curr * 10 + root->val;
		return sumHelp(root->left, curr) + sumHelp(root->right, curr);
	}
};