#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Map = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
class Solution
{
public:
	void recursion(string digits, vector<string> &words)
	{
		int digit = stoi(digits.substr(0, 1));
		if (digit > 1)
		{
			string str = Map[digit];
			for (auto &word : words)
			{
				for (auto c : str)
				{
					
				}
			}
		}
	}
	vector<string> letterCombinations(string digits)
	{
		vector<string> words;
		
	}
};