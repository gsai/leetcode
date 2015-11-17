#include <vector>

using namespace std;

class Solution
{
public:
	int findMin(vector<int> &nums)
	{
		int h = 0, t = nums.size() - 1;
		int mid;

		while (h < t)
		{
			mid = (h + t) / 2;
			if (nums[mid]>nums[t]) h = mid + 1;
			else t = mid;
		}
		return nums[h];
	}
};