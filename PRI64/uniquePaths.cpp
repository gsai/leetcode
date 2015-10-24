#include <iostream>

using namespace std;
const int MAX_SIZE = 100;
class Solution
{
private:
	int map[MAX_SIZE][MAX_SIZE];
public:
	void calPaths()
	{
		for (int i = 1; i < MAX_SIZE; i++)
		{
			map[1][i] = 1;
			map[i][1] = 1;
		}
		for (int i = 2; i < MAX_SIZE; i++)
		{
			for (int j = 2; j < MAX_SIZE; j++)
			{
				map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
		}
	}
	int uniquePaths(int m, int n)
	{
		calPaths();
		return map[m][n];
	}
};

