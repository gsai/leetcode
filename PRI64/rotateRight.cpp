struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

class Solution
{
public:
	static ListNode* swapList(ListNode *head_)
	{
		if (head_ == nullptr || head_->next == nullptr)
			return head_;
		
		ListNode *prev = head_;
		ListNode *nextNode = head_->next;
		head_->next = nullptr;
		while (nextNode)
		{
			ListNode *tmp = nextNode->next;
			nextNode->next = prev;
			prev = nextNode;
			nextNode = tmp;
		}
		return prev;
	}
	static ListNode* getTail(ListNode *head_,int &size_)
	{
		if (head_ == nullptr || head_->next == nullptr)
		{
			size_ = head_ ? 1 : 0;
			return head_;
		}
		size_ = 1;
		while (head_->next != nullptr)
		{
			head_ = head_->next;
			size_++;
		}
		return head_;
	}
	ListNode* rotateRight(ListNode *head, int k)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		int size = 0;
		ListNode *tailNode = getTail(head,size);
		tailNode->next = head;
		
		int count = 1;
		int offset = size - k%size;

		while (count < offset)
		{
			head = head->next;
			count++;
		}

		ListNode *result = head->next;
		head->next = nullptr;
		return result;
	}
};