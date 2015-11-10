#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
	//有问题，一些解漏掉，待会查查原因，不过这个题目考察的是hashtable，我的做法不大对
	vector<vector<int>> fourSum(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		int head = 0;
		int tail = nums.size() - 1;
		int id1, id2;
		vector<vector<int> > lines;

		while (head+2 < tail)
		{
			id1 = head + 1;
			id2 = tail - 1;
			while (id1 < id2)
			{
				if (nums[head] + nums[tail] + nums[id1] + nums[id2] == target)
				{
					vector<int> line = { nums[head], nums[id1], nums[id2], nums[tail] };
					lines.push_back(line);
					id1++;
					id2--;
				}
				else
				{
					if (nums[head] + nums[tail] + nums[id1] + nums[id2] < target)
						id1++;
					else
						id2--;
				}
			}
			if (nums[head] + nums[head + 1] + nums[tail] + nums[tail - 1] == target)
			{
				head++;
				tail--;
			}
			else if (nums[head] + nums[head + 1] + nums[tail] + nums[tail - 1] < target)
					head++;
				else
					tail--;
		}
		return lines;
	}
	/*
	vector<vector<int>> _4Sum(vector<int> &nums, int target)
	{
		vector< pair<int, pair<int, int> > > hashTable;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				pair<int, int> tmp(i, j);
				hashTable.emplace_back(pair<int, pair<int, int> >(nums[i] + nums[j], tmp));
			}
		}

		sort(hashTable.begin(), hashTable.end(), [](pair<int, pair<int, int> > lf, pair<int, pair<int, int> > rt){return lf.first < rt.first; });

		vector<vector<int> > lines;
		int head = 0;
		int tail = nums.size() - 1;

		while (head < tail)
		{
			int tie = hashTable[head].first + hashTable[tail].first;
			if (tie == target)
			{
				vector<int> line = { hashTable[head].second.first, hashTable[head].second.second,
									 hashTable[tail].second.first, hashTable[tail].second.second };
				lines.push_back(line);
				if (hashTable[head].first == hashTable[head+1].first)

			}
		}
	}*/
};

