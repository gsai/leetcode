#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> sums;
		sort(nums.begin(), nums.end());
	
		int head = 0, tail = nums.size() - 1;
		while (head < tail)
		{
			if (nums[head] + nums[tail] == target)
			{
				sums.push_back(nums[head]);
				sums.push_back(nums[tail]);
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
		return sums;
	}
	//so Âý£¬Âý
	vector<int> twoSum2(vector<int> &nums, int target)
	{
		vector<int> indexs;
		for (auto it = nums.begin(); it != nums.end();it++ )
		{
			vector<int>::iterator itfind = find(it + 1, nums.end(), target-(*it));
			if (itfind != nums.end())
			{
				indexs.push_back(static_cast<int>(it - nums.begin()) + 1);
				indexs.push_back(static_cast<int>(itfind - nums.begin()) + 1);
			}
		}
		return indexs;
	}
	//using map
	vector<int> twoSum3(vector<int> &nums, int target)
	{
		map<int, int> table;
		vector<int> indexs;
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = table.find(target - nums[i]);
			if (it != table.end())
			{
				int id1 = min(i, it->second);
				int id2 = max(i, it->second);
				indexs.push_back(id1+1);
				indexs.push_back(id2+1);
			}
			else
			{
				table.emplace(nums[i], i);
			}
		}
		return indexs;
	}
};

