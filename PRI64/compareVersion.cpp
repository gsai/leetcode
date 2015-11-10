#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
	void split(string &s, char dilim, vector<int> &elems)
	{
		stringstream ss(s);
		string item;

		while (getline(ss, item, dilim))
		{
			if (!item.empty())
			{
				elems.push_back(stoi(item));
			}
		}
	}
	
	int compareVersion(string version1, string version2)
	{
		vector<int> one, two;
		split(version1, '.', one);
		split(version2, '.', two);

		int index;
		for (index = 0; index < one.size() && index < two.size(); index++)
		{
			if (one[index] != two[index])
				return (one[index] > two[index]) ? 1 : -1;
		}

		for (; index < one.size(); index++)
		{
			if (one[index]>0)
				return 1;
		}

		for (; index < two.size(); index++)
		{
			if (two[index]>0)
				return -1;
		}
		return 0;
	}
};
