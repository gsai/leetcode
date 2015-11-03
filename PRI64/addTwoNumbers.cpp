#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *head = NULL;
		ListNode *curr = NULL;
		int carry = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;

			int value = (val1 + val2 + carry) % 10;
			carry = (val1 + val2 + carry) / 10;
			ListNode *p = new ListNode(value);
			if (head == NULL) head = p;
			if (curr) curr->next = p;
			curr = p;
		}
		if (carry != 0)
		{
			ListNode *p = new ListNode(carry % 10);
			curr->next = p;
		}

		return head;
	}
};
