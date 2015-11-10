#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	int myAtoi(string str)
	{
		if (str.empty())
			return 0;

		bool sign = str[0] == '-' ? true : false;
		if (sign)
			str = str.substr(1);
		if (!sign)
		{
			if (str[0] == '+')
				str = str.substr(1);
		}

		if (str.empty())
			return 0;

		string::size_type idx = str.find_first_not_of('0');
		if (idx == string::npos)
			return 0;
		str = str.substr(idx);

		string::size_type n = str.size();
		int ans = 0;
		int base = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			ans = ans + base*(str[i] - '0');
			base = base * 10;
		}
		if (sign)
			return 0 - ans;
		else
			return ans;
	}
};
