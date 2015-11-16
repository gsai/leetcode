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
	bool isValidBST(TreeNode *root)
	{
		if (root == nullptr) return true;
		return inOrder(root, root->left, root->right);
	}
private:
	bool inOrder(TreeNode *root, TreeNode *lf, TreeNode *rt)
	{
		if (root == nullptr) return true;

		if ((lf != nullptr && lf->val >= root->val) || (rt != nullptr && rt->val <= root->val))
			return false;
		
		return inOrder(root->left, root->left->left, root->left->right) && inOrder(root->right, root->right->left, root->right->right);
	}
};