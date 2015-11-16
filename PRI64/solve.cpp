#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
	bool judge(int x, int y,int m,int n)
	{
		if (x > -1 && x<m && y>-1 && y < n)
			return true;
		else
			return false;
	}
	void bfs(vector<vector<char>> &board, int x, int y)
	{
		queue<pair<int, int>> q;
		int m = board.size();
		int n = board[0].size();

		q.emplace(x, y);
		while (!q.empty())
		{
			pair<int, int> elem = q.front();
			q.pop();

			int i = elem.first;
			int j = elem.second;
			board[i][j] = '#';
			
			if (judge(i - 1, j, m, n) && board[i - 1][j] == 'o')
				q.emplace(i - 1, j);
			if (judge(i + 1, j, m, n) && board[i + 1][j] == 'o')
				q.emplace(i + 1, j);
			if (judge(i, j - 1, m, n) && board[i][j - 1] == 'o')
				q.emplace(i, j - 1);
			if (judge(i, j + 1, m, n) && board[i][j + 1] == 'o')
				q.emplace(i, j + 1);
		}
	}
	void solve(vector<vector<char>> &board)
	{
		if (board.size() == 0)
			return;
		if (board[0].size() == 0)
			return;

		int row = board.size();
		int col = board[0].size();

		for (int i = 0; i < row; i++)
		{
			if (board[i][0] == 'o')
				bfs(board, i, 0);
			if (board[i][col - 1] == 'o')
				bfs(board, i, col - 1);
		}
		for (int j = 0; j < col; j++)
		{
			if (board[0][j] == 'o')
				bfs(board, 0, j);
			if (board[row - 1][j] == 'o')
				bfs(board, row - 1, j);
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == 'o')
					board[i][j] = 'x';
				if (board[i][j] == '#')
					board[i][j] = 'o';
			}
		}
	}
};