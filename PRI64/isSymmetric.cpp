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
	bool isSymmetric(TreeNode *root)
	{
		if (root == nullptr) return true;

		return recursiveHelp(root->left, root->right);
	}
private:
	bool recursiveHelp(TreeNode *left, TreeNode *right)
	{
		if (left == nullptr || right == nullptr)
			return left == right;

		if (left->val != right->val)
			return false;
		return recursiveHelp(left->left, right->right) && recursiveHelp(left->right, right->left);
	}
};