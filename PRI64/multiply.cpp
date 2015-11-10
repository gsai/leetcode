#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		long long i1 = stol(num1);
		long long i2 = stol(num2); 
		return to_string(i1*i2);
	}
};

