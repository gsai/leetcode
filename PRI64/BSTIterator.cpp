#include <vector>

using std::vector;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

class BSTIterator
{
public:
	BSTIterator(TreeNode *root)
	{
		BSTHelp(root);
	}

	bool hasNext()
	{
		return it == data.end();
	}

	int next()
	{
		return *(it++);
	}
private:
	void BSTHelp(TreeNode *root)
	{
		if (root == nullptr)
			return;
		BSTHelp(root->left);
		data.push_back(root->val);
		BSTHelp(root->right);
	}

	vector<int> data;
	vector<int>::iterator it = data.begin();
};