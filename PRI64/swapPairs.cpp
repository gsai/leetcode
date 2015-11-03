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
	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *nextNode = head->next;
		ListNode *nextHead = nextNode->next;

		nextNode->next = head;
		head->next = swapPairs(nextHead);

		return nextNode;
	}
};