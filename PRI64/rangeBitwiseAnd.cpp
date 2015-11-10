#include <iostream>
using namespace std;
class Solution
{
public:
	int rangeBitwiseAnd(int m, int n)
	{
		int movefactor = 1;
		while (m!=n)
		{
			m >>= 1;
			n >>= 1;
			movefactor <<= 1;
		}
		return m*movefactor;
	}
};
