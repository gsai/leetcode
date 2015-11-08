#include <queue>
using namespace std;
class MedianFinder
{
private:
	priority_queue<int> small, large;
public:
	void addNum(int num)
	{
		small.push(num);
		large.push(-small.top());
		small.pop();
		if (small.size() < large.size())
		{
			small.push(-large.top());
			large.pop();
		}
	}

	double findMedian()
	{
		return small.size()>large.size()
			? small.top()
			: (small.top() - large.top()) / 2.0;
	}
};