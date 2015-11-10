#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
	vector<int> searchRange(vector<int> &nums, int target)
	{
		if (nums.empty())
			return{ -1, -1 };

		vector<int> idxs = { -1, -1 };
		int i = 0, j = nums.size() - 1;
		int mid;
		while (i < j)
		{
			mid = (i + j) / 2;
			if (nums[mid] < target) i = mid + 1;
			else j = mid;
		}

		if (nums[i] != target) return idxs;
		else idxs[0] = i;

		j = nums.size() - 1;
		while (i < j)
		{
			mid = (i + j) / 2 + 1;
			if (nums[mid] > target) j = mid - 1;
			else i = mid;
		}
		idxs[1] = j;
		return idxs;
	}
};