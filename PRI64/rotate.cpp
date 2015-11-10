#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int> > &matrix)
	{
		reverse(matrix.begin(), matrix.end());
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = i+1; j < matrix[0].size(); j++)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};
/*
int main()
{
	Solution sln;
	vector<vector<int> > v = 
	{ { 1, 2, 3 },
	  { 4, 5, 6 },
   	  { 7, 8, 9 } };
	
	sln.rotate(v);
	for (auto vi : v)
	{
		for (auto i : vi)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
*/