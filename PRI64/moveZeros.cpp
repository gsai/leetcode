#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
	void moveZeroes(vector<int> &nums)
	{
		std::remove(nums.begin(), nums.end(), 0);
	}
};