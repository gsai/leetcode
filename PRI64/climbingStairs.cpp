#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int climbStairs(int n)
	{
		vector<int> steps = { 0, 1, 2 };
		for (int i = 3; i < n+1; i++)
		{
			int num = steps[i - 1] + steps[i - 2];
			steps.push_back(num);
		}
		return steps[n];
	}
};