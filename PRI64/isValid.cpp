#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		
		stack<char> sc;

		for (auto c : s)
		{
			if (c == '[' || c == '(' || c == '{')
				sc.push(c);
			else
			{
				if (c == ']')
				{
					if (sc.top() == '[')
						sc.pop();
					else
						return false;
				}
				else
				{
					if (c == ')')
					{
						if (sc.top() == '(')
							sc.pop();
						else
							return false;
					}
					else
					{
						if (sc.top() == '{')
							sc.pop();
						else
							return false;
					}
				}
			}
		}
		
		return sc.empty() ? true : false;
	}
};

