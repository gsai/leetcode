#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	int minSubArrayLen(int s, vector<int> &nums)
	{
		int n = nums.size(), start = 0, minLen = INT_MAX, sum = 0;

		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
			while (sum >= s)
			{
				minLen = min(minLen, i - start + 1);
				sum -= nums[start++];
			}
		}
		return minLen == INT_MAX ? 0 : minLen;
	}
};