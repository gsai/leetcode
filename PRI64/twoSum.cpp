#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<int> twoSum1(vector<int> &nums, int target)
	{
		vector<int> sum;
		sort(nums.begin(), nums.end());
	
		int head = 0, tail = nums.size() - 1;
		while (head < tail)
		{
			if (nums[head] + nums[tail] == target)
			{
				sum.push_back(nums[head]);
				sum.push_back(nums[tail]);
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
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> dict(target+1, -1);
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= target)
			{
				dict[target - nums[i]] = i;
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (dict[nums[i]] != -1)
				result.push_back(i);
		}
		return result;
	}
};

