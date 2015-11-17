#include <algorithm>

using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

class Solution
{
public:
	ListNode* insertionSortList(ListNode *head)
	{
		if (head == nullptr) return head;
		ListNode *p = head->next;
		ListNode *guard;

		while (p != nullptr)
		{
			guard = head;
			while (guard != p)
			{
				if (guard->val >= p->val)
					break;
				guard = guard->next;
			}
			
			if (guard != p)
			{
				ListNode *tmp = guard->next;
				guard->next = p;
				ListNode *pNext = p->next;
				p->next = tmp;
				swap(p->val, guard->val);
				p = pNext;
			}
			else
				p = p->next;
		}

		return head;
	}
};