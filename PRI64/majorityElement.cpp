#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int majorityElement(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};
