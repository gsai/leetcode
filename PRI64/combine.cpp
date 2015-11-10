#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
	vector<vector<int> > combine(int n, int k)
	{
		vector<int> p, nums;
		for (int i = 0; i < n; i++)
			nums.push_back(i + 1);

		p.insert(p.end(), k, 1);
		p.insert(p.end(), n - k, 0);

		
		vector<vector<int> > ans;
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
		return ans;
	}
};
