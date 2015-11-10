#include <vector>
#include <string>
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
	vector<string> binaryTreePaths(TreeNode* root)
	{
		vector<string> ans;
		string str("");
		generate(root, ans, str);

		return ans;
	}
private:
	void generate(TreeNode *root, vector<string> &lines, string s)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			s += root->val;
			lines.push_back(s);
			return;
		}
		s += root->val;
		s += "->";
		if (root->left != nullptr)
			generate(root->left, lines, s);
		if (root->right != nullptr)
			generate(root->right, lines, s);
	}
};