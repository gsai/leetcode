#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item
{
	int score;
	vector<int> seque;
	bool operator<(Item &rh) const
	{
		return score < rh.score;
	}
	bool next()
	{
		if (seque.empty())
			return false;
		score = seque.front();
		vector<int>::iterator it = seque.begin();
		seque.erase(it);
		return true;
	}
};
class Solution
{
public:
	vector<int> generateSequence()
	{
		vector<int> sequence;
		int nums = rand();
		for (int i = 0; i < nums; i++)
		{
			sequence.push_back(rand());
		}
		sort(sequence.begin(), sequence.end());
		return sequence;
	}
	vector<int> mergeN(vector<Item> inputs)
	{
		make_heap(inputs.begin(), inputs.end());
		vector<int> output;
		while (!inputs.empty())
		{
			pop_heap(inputs.begin(), inputs.end());
			output.push_back(inputs.back().score);
			if (!inputs.back().next())
			{
				inputs.pop_back();
			}
		}

		return output;
	}
	
};
