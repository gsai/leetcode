#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<int> singleNumber(vector<int> &nums)
	{
		int diff = 0;
		for (auto i : nums) diff ^= i;

		cout << diff << endl;
		int mask = 1;
		while ((diff&mask)== 0)
		{
			mask = mask * 2;
		}
		//another simple method
		diff &= -diff;
		cout << mask << endl;
		vector<int> ans = { 0, 0 };
		for (auto i : nums)
		{
			if ((i&mask) == 0)
				ans[0] ^= i;
			else
				ans[1] ^= i;
		}
		return ans;
	}
};

