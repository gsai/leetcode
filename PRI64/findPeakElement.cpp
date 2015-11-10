#include <vector>
using namespace std;

class Solution
{
public:
	int findPeakElement(vector<int> &nums)
	{
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				if (nums[0]>INT_MIN && nums[0] > nums[1])
					return 0;
			}
			if (i == n - 1)
			{
				if (nums[n - 1] > nums[n - 2])
					return n - 1;
			}
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
				return i;
		}
	}
};

