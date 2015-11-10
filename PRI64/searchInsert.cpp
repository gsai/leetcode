#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
	int searchInsert(vector<int> &nums, int target)
	{
		if (nums.empty())
			return 0;
		int index = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i] <= target)
				index = i;
			else
				break;
		}
		if (nums[index] >= target)
			return index;
		else if (nums[index] < target)
				return index + 1;

	}
};
