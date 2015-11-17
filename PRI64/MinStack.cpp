#include <algorithm>
#include <climits>

class MinStack
{
public:
	void push(int x)
	{
		data[++curr] = x;
		min = x < min ? x : min;
	}

	void pop()
	{
		if (min == data[curr])
		{
			min = *(std::min_element(data, data + curr));
		}
		curr--;
	}

	int top()
	{
		return data[curr];
	}

	int getMin()
	{
		return min;
	}
private:
	int data[100001];
	int min = INT_MIN;
	int curr = -1;
};