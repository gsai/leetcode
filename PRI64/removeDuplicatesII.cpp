#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		map<int, int> tables;
		for (int num : nums)
		{
			tables[num]++;
		}	

		nums.clear();
		for (auto i : tables)
		{
			int loop = i.second <= 2 ? i.second : 2;
			for (int j = 0; j < loop; j++)
				nums.push_back(i.first);
		}
		return nums.size();
	}
};

