#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		m = board.size();
		n = board[0].size();
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (DFSearch(board, word, i, j))
					return true;
			}
		}
		return false;
	}
private:
	int m;
	int n;
	bool DFSearch(vector<vector<char>> &board, string word, int x, int y)
	{
		if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '\0'|| board[x][y] != word[0])
			return false;

		if (word.size() == 1)
			return true;
		
		char c = board[x][y];
		board[x][y] = '\0';
		if (DFSearch(board, word.substr(1), x - 1, y) || DFSearch(board, word.substr(1), x, y - 1) || DFSearch(board, word.substr(1), x + 1, y) || DFSearch(board, word.substr(1), x, y + 1))
			return true;
		board[x][y] = c;
		return false;
	}
};

