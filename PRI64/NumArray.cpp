#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

class NumArray
{
public:
	NumArray(vector<int> &nums)
	{
		vec = nums;
	}

	int sumRange(int i, int j)
	{
		return accumulate(vec.begin() + i, vec.begin() + j+1, 0);
	}
private:
	vector<int> vec;
};

//Your NumArray object will be instantiated and called as such:
//NumArray numArray(nums);
//numArray.sumRange(0,1);
//numArray.sumRange(1,2);

