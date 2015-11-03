#include <vector>
#include <set>
#include <iostream>

using namespace std;
class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		multiset<int> digits;
		for (auto num : nums)
			digits.insert(num);

		nums.clear();
		for (auto it = digits.begin(); it != digits.end(); it++)
		{
			nums.push_back(*it);
		}
	}
};
