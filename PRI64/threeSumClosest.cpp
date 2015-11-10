#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		if (nums.size() <= 3)
			return accumulate(nums.begin(), nums.end(), 0);

		sort(nums.begin(), nums.end());
		int ans = INT_MAX;//不合适，要改
		int sum;

		for (int i = 0; i < nums.size() - 2; i++)
		{
			int head = i + 1;
			int tail = nums.size() - 1;
			
			while (head < tail)
			{
				sum = nums[i] + nums[head] + nums[tail];
				if (abs(target - sum) < abs(target - ans))
					ans = sum;
				if (ans == target)
					return target;
				sum>ans ? tail-- : head++;
			}
		}
		return ans;
	}
};