#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

using namespace std;
class Solution
{
public:
	vector<vector<int> > subsetsWithDup(vector<int> &nums)
	{
		set<vector<int> > sets;
		sort(nums.begin(), nums.end());
		int n = nums.size();

		for (int i = 0; i < n + 1; i++)
		{
			vector<int> p;
			p.insert(p.end(), i, 1);
			p.insert(p.end(), n - i, 0);
			vector<int> line;
			do
			{
				for (int j = 0; j < p.size(); j++)
				{
					if (p[j])
						line.push_back(nums[j]);
				}
				sets.insert(line);
			} while (prev_permutation(p.begin(), p.end()));
		}
		
		vector<vector<int> > ans;
		copy(sets.begin(), sets.end(), back_inserter(ans));
		//or use range constructor
		//vector<vector<int> > ans(sets.begin(),sets.end());
		//return ans;
	}
};