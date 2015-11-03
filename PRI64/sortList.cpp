#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution
{
public:
	ListNode* sortList(ListNode *head)
	{
		if (head == NULL)
			return NULL;
		vector<int> nums;

		ListNode *p = head;
		while (p != NULL)
		{
			nums.push_back(p->val);
			p = p->next;
		}
		sort(nums.begin(), nums.end());
		p = head;
		vector<int>::size_type index = 0;
		while (p != NULL)
		{
			p->val = nums[index];
			index++;
			p = p->next;
		}
		return head;
	}
};