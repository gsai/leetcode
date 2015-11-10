#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		vector<int>::iterator duplicate = unique(nums.begin(), nums.end(), [](int lf, int rt){return lf == rt; });
		nums.erase(duplicate, nums.end());
		return nums.size();
	}
};

