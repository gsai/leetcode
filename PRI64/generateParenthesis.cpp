#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> vecStr;
		string s;
		generateUtil(0, 0, n, vecStr, s);

		return vecStr;
	}
	
	void generateUtil(int left, int right, int n, vector<string> &alls, string str)
	{
		if (right == n)
		{
			alls.push_back(str);
			return;
		}
		
		if (left < n)
		{
			str += "(";
			generateUtil(left + 1, right, n, alls, str);
			str.pop_back();
		}
		if (left > right)
		{
			str += ")";
			generateUtil(left, right + 1, n, alls, str);
		}
	}
};

