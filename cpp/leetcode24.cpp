class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
		if (!head) return NULL;
		if (!head->next) return head;
		ListNode * slow = head, * fast = head->next, * ret = fast;
		while (true)
		{
			ListNode * tmp = fast->next;
			fast->next = slow;
			slow->next = tmp;
			swap(slow, fast);
			if (!(fast->next) || !(fast->next->next)) break;
			ListNode * save = fast;
			fast = fast->next->next;
			slow = slow->next->next;
			save->next = fast;
		}
		return ret;
    }
};
