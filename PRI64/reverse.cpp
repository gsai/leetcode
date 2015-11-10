#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
	int reverse(int x)
	{
		string str = to_string(x);
		bool sign = x >= 0 ? true : false;

		std::reverse(str.begin(), str.end());
		if (!sign)
		{
			str = "-" + str;
			str = str.substr(0, str.size() - 1);
		}

		return stoi(str);
	}
};

int Rmain()
{
	Solution sln;
	cout << sln.reverse(1534236469) << endl;

	return 0;
}