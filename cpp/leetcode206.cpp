/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
	ListNode* reverseList(ListNode* head) 
	{
		ListNode * now = head, * last = NULL;
		while (now)
		{
			ListNode * pre = now->next;
			now->next = last;
			last = now;
			now = pre;
		}
		return last;
	}
};