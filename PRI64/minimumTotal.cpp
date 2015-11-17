#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int minimunTotal(vector<vector<int>> &triangle)
	{
		vector<vector<int>> sum = triangle;

		for (int i = 1; i < triangle.size(); i++)
		{
			sum[i][0] = sum[i - 1][0] + triangle[i][0];
			sum[i][i] = sum[i - 1][i - 1] + triangle[i][i];
		}
		
		for (int i = 1; i < triangle.size(); i++)
		{
			for (int j = 1; j < i; j++)
			{
				sum[i][j] = min(sum[i - 1][j - 1], sum[i - 1][j]) + triangle[i][j];
			}
		}

		return *(min_element(sum[sum.size() - 1].begin(), sum[sum.size() - 1].end()));
	}
};

