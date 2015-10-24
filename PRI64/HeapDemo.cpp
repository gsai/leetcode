#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace HeapDemo
{
	void Print(int n)
	{
		cout << n << " ";
	}
	void test()
	{
		int iarray[] = { 1, 24, 53, 9, 7, 3, 56 };
		vector<int> v1(iarray, iarray + sizeof(iarray)/sizeof(int));
		make_heap(v1.begin(), v1.end());

		while (!v1.empty())
		{
			pop_heap(v1.begin(), v1.end());
			int top = v1.back();
			cout << top << " ";
			v1.pop_back();
		}
	}

	class Solution
	{
	public:
		int nthUglyNumber(int n)
		{
			vector<int> result(1, 1);
			int i = 0, j = 0, k = 0;
			while (result.size() < n)
			{
				result.push_back(min(result[i] * 2, min(result[j] * 3, result[k] * 5)));
				if (result.back() == result[i] * 2) i++;
				if (result.back() == result[j] * 3) j++;
				if (result.back() == result[k] * 5) k++;
			}

			return result.back();
		}
	};

	void testMap()
	{
		multimap<int, string> strMap;
		strMap.insert(pair<int, string>(0, "0"));
		strMap.insert(multimap<int, string>::value_type(1, "1"));
		strMap.insert(multimap<int, string>::value_type(2, "2"));

		for (auto it : strMap)
		{
			cout << "(" << it.first << "," << it.second << ")" << endl;
		}

	} 
	
}

