#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		if (strs.size() <= 1)
			return strs.size() == 0 ? "" : strs[0];

		int n = strs.size();
		int len = strs[0].size();
		string ans;

		for (int i = 0; i < len; i++)
		{
			char token = strs[0][i];
			for (auto s : strs)
			{
				if (s.size() <= i)
					return ans;
				else
				{
					if (s[i] != token)
						return ans;
				}
			}
			ans += token;
		}
		return ans;
	}
};