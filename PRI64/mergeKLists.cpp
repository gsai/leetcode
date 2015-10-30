#include <algorithm>
#include <cstdlib>
#include <vector>
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
	ListNode* mergeKLists(vector<ListNode*> &lists)
	{
		if (lists.empty())
			return NULL;
		for (auto it = lists.begin(); it != lists.end();)
		{
			if ((*it) == NULL)
				it = lists.erase(it);
			else
				it++;
		}
		if (lists.empty())
			return NULL;

		ListNode *head = new ListNode(0);
		ListNode *curr = head;
		make_heap(lists.begin(), lists.end(), [](ListNode *lt, ListNode *rh){ return lt->val < rh->val; });
		while (!lists.empty())
		{
			pop_heap(lists.begin(), lists.end());
			curr->next = lists.back();
			curr = lists.back();
			if (lists.back()->next == NULL)
			{
				lists.pop_back();
			}
			else
			{
				lists[lists.size() - 1] = lists.back()->next;
				push_heap(lists.begin(), lists.end());
			}
		}
		curr->next = NULL;
		return head->next;
	}
};

int main()
{
	int loop = 10;
	vector<ListNode*> input;
	srand(12345);
	for (int i = 0; i < loop; i++)
	{
		ListNode *head = new ListNode(rand());
		ListNode *c = head;
		for (int j = 0; j < loop; j++)
		{
			ListNode *p = new ListNode(rand());
			c->next = p;
			c = c->next;
		}
		input.push_back(head);
	}

	for (auto i : input)
	{
		while (i != NULL)
		{
			cout << i->val << " ";
			i = i->next;
		}
		cout << endl;
	}
	

	
	vector<int> v;
	for (int i = 0; i < loop; i++)
	{
		v.push_back(rand());
	}
	make_heap(v.begin(), v.end());
	for (int i = 0; i < loop; i++)
	{
		pop_heap(v.begin(), v.end());
		v[v.size() - 1] = v.back() + 1;
		push_heap(v.begin(), v.end());
	}
	cout << "pop&push:";
	for (auto i : v)
		cout << i << " ";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		v.erase(it);
	}
	cout << v.size();
	cout << endl;
	
	return 0;
}