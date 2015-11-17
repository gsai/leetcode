#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	void rotate(vector<int> &nums, int k)
	{
		if (k > nums.size())
			k %= nums.size();

		int rot = nums.size() - k;
		vector<int>::iterator beg = nums.begin();

		reverse(beg, beg + rot);
		reverse(beg + rot, nums.end());
		reverse(nums.begin(), nums.end());
	}
};

