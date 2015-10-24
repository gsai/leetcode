#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
	string fractionToDecimal(int numerator, int denominator)
	{
		double num = static_cast<double>(numerator);
		double den = static_cast<double>(denominator);

		double quot = num / den;
		stringstream ss(stringstream::in | stringstream::out);
		ss << quot;
		return ss.str();
	}
};

