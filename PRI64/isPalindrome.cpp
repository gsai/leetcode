#include <cctype>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		if (s.size() <= 1)
			return true;

		int lf = 0;
		int rt = s.size() - 1;
		while (lf < rt)
		{
			
			while (lf < rt && !isalnum(s[lf])) lf++;
			while (lf < rt && !isalnum(s[rt])) rt--;

			if (lf == rt)
				return true;

			char lowLF = tolower(s[lf]);
			char lowRT = tolower(s[rt]);
			if (lowLF != lowRT)
				return false;
			lf++;
			rt--;
		}

		return true;
	}
};

