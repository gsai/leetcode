#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int> &nums)
	{
		next_permutation(nums.begin(), nums.end());
	}
};
