#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> sum;
		sort(nums.begin(), nums.end());
	
		int head = 0, tail = nums.size() - 1;
		while (head < tail)
		{
			if (nums[head] + nums[tail] == target)
			{
				sum.push_back(head + 1);
				sum.push_back(tail + 1);
				head++;
				tail--;
			}
		   if (nums[head] + nums[tail] < target)
			{
				head++;
			}
		   if (nums[head] + nums[tail] > target)
			{
				tail--;
			}
		}
		return sum;
	}
};

