#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> lists;
		if (digits.empty())
			return lists;

		vector<string> hashMap = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	}
	void recurseCombinations(string digits, vector<string> &lists)
	{
		if (digits.empty())
			return;


	}
};