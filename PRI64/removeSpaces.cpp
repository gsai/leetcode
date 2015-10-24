#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

	bool isContinousSpaces(char x, char y)
	{
		return x == ' ' && y == ' ';
	}

	void removeContinousSpaces(string &str)
	{
		string::iterator last = unique(str.begin(), str.end(), isContinousSpaces);
		str.erase(last, str.end());
	}


