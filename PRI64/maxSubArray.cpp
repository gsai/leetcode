#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		int maxNow = nums[0];
		int maxEndingHere = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
			maxNow = max(maxEndingHere, maxNow);
		}
		return maxNow;
	}
};