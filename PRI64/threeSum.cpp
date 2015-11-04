#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<vector<int> > threeSum(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());

		vector<vector<int> > lines;
		int head, tail, sum;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			head = i + 1;
			tail = n - 1;
			while (head < tail)
			{
				sum = nums[i] + nums[head] + nums[tail];
				if (sum == 0)
				{
					vector<int> line = { nums[i], nums[head], nums[tail] };
					lines.push_back(line);
					while(head<tail && nums[head]==nums[head+1]) head++;
					while(head<tail && nums[tail]==nums[tail-1]) tail--;
				}
				else if (sum > 0)
					tail--;
				else
					head++;
			}
			while (i < n - 1 && nums[i] == nums[i + 1]) i++;
		}
		
		return lines;
	}
};

int main()
{
	Solution sln;
	vector<int> v = { -1, 0, 1, 2, -1, -4 };
	for (auto vi : sln.threeSum(v))
	{
		for (auto i : vi)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}