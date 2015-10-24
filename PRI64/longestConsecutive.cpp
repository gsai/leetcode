#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		
		set<int>  intSet;
		for (int num : nums)
		{
			intSet.insert(num);
		}

		int longest = 1;
		for (int num : nums)
		{
			if (intSet.find(num) != intSet.end())
			{
				int sum = 1;
				intSet.erase(num);
				int  val = num;
				while (intSet.find(--val) != intSet.end())
				{
					sum++;
					intSet.erase(val);
				}

				val = num;
				while (intSet.find(++val) != intSet.end())
				{
					sum++;
					intSet.erase(val);
				}
				longest = max(longest, sum);
			}
	
		}

		return longest;
	}
};
