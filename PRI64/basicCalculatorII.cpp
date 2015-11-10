#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
	int calculate(string s)
	{
		deque<int> digits;
		deque<char> opts;
		istringstream iss(s);
		int digit;
		iss >> digit;
		digits.push_back(digit);
		char opt;
		while (iss >> opt)
		{
			iss >> digit;
			digits.push_back(digit);
			opts.push_back(opt);

			if (opt == '*')
			{
				int right = digits.back();
				digits.pop_back();
				int left = digits.back();
				digits.pop_back();
				digits.push_back(left*right);
				opts.pop_back();
			}
			if (opt == '/')
			{
				int right = digits.back();
				digits.pop_back();
				int left = digits.back();
				digits.pop_back();
				digits.push_back(left/right);
				opts.pop_back();
			}
		}
		while (!opts.empty())
		{
			int left = digits.front();
			digits.pop_front();
			int right = digits.front();
			digits.pop_front();

			if (opts.front() == '+')
				digits.push_front(left + right);
			if (opts.front() == '-')
				digits.push_front(left - right);
			
			opts.pop_front();
		}
		
		return digits.front();
	}
};
