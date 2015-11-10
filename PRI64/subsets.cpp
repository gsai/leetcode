#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
	vector<vector<int>> subsets(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int> > ans;
		int n = nums.size();

		for (int k = 0; k < n + 1; k++)
		{
			vector<int> p;
			p.insert(p.end(), k, 1);
			p.insert(p.end(), n - k, 0);

			do
			{
				vector<int> line;
				for (int i = 0; i < n; i++)
				{
					if (p[i])
						line.push_back(nums[i]);
				}
				ans.push_back(line);
			} while (prev_permutation(p.begin(),p.end()));
		}
		return ans;
	}
};