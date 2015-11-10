struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

class Solution
{
public:
	static ListNode* reverse(ListNode *head_)
	{
		if (head_ == nullptr || head_->next == nullptr)
			return head_;

		ListNode *prev = head_;
		ListNode *nextNode = head_->next;
		head_->next = nullptr;

		while (nextNode != nullptr)
		{
			ListNode *tmp = nextNode->next;
			nextNode->next = prev;
			prev = nextNode;
			nextNode = tmp;
		}
		return prev;
	}
	ListNode* reverseKGroup(ListNode *head, int k)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		int count = 1;
		ListNode *node = head;
		while (count < k && node != nullptr)
		{
			count++;
			node = node->next;
		}
		
		if (count == k)
		{
			ListNode *kPlus1 = node->next;
			node->next = nullptr;
			ListNode *newHead = reverse(head);
			head->next = reverseKGroup(kPlus1, k);
			return newHead;
		}
		else
		{
			return head;
		}
		
	}
};