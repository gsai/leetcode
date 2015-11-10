#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	void recursionSum(vector<vector<int> > &ans,vector<int> &candidates, int target, vector<int> &current, int idx)
	{
		if (target == 0)
		{
			ans.push_back(current);
			return;
		}

		int n = candidates.size();
		for (int i = idx; i < n && candidates[i] <= target; i++)
		{
			current.push_back(candidates[i]);
			recursionSum(ans, candidates, target - candidates[i], current, i);
			current.pop_back();
		}
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > lines;
		vector<int> line;

		recursionSum(lines, candidates, target, line, 0);

		return lines;
	}
};

int Cmain()
{
	vector<int> cand = { 2, 3, 6, 7 };
	Solution sln;
	for (auto line : sln.combinationSum(cand, 7))
	{
		for (auto i : line)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}