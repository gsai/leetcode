struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

class Solution
{
public:
	ListNode* swapPairs(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *nextNode = head->next;
		ListNode *nextHead = nextNode->next;

		nextNode->next = head;
		head->next = swapPairs(nextHead);

		return nextNode;
	}
};