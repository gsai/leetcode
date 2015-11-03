#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string largestNumber(vector<int> &nums)
	{
		vector<string> digits;
		for (auto i : nums)
		{
			digits.push_back(to_string(i));
		}

		sort(digits.begin(), digits.end(), [](string lf, string rt){return lf + rt > rt + lf; });
		
		return accumulate(digits.begin(), digits.end(), string(""));
	}
};
