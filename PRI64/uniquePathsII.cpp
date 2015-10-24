#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int uniquePathWithObstacles(vector<vector<int>> &obstacleGrad)
	{
		size_t m = obstacleGrad.size();
		size_t n = obstacleGrad[0].size();

		for (int i = 0; i < m; i++)
		{
			grad[i][0] = obstacleGrad[i][0];
		}
		for (int i = 0; i < n; i++)
		{
			grad[0][i] = obstacleGrad[0][i];
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; i < n; j++)
			{
				if (obstacleGrad[i - 1][j] == 0 && obstacleGrad[i][j - 1] == 0)
					obstacleGrad[i][j] = obstacleGrad[i - 1][j] + obstacleGrad[i][j - 1];
				
				if (obstacleGrad[i - 1][j] == 0 && obstacleGrad[i][j - 1] == 1)
					obstacleGrad[i][j] = obstacleGrad[i - 1][j];

				if (obstacleGrad[i - 1][j] == 1 && obstacleGrad[i][j - 11] == 0)
					obstacleGrad[i][j] = obstacleGrad[i][j - 1];

				if (obstacleGrad[i - 1][j] == 1 && obstacleGrad[i][j = 1] == 1)
					obstacleGrad[i][j] = 0;
			}
		}

		return grad[m - 1][n - 1];
	}
private:
	int grad[100][100];
};
