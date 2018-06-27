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
    ListNode* oddEvenList(ListNode* head) 
	{
        if (head == NULL || head->next == NULL) return head;
		ListNode * odd = head, * even = head->next;
		ListNode * pre = even, * last = odd;
		int cnt = 0;
		while (pre->next)
		{
			cnt++;
			last->next = pre->next;
			last = pre;
			pre = pre->next;
		}
		if (cnt & 1)
		{
			last->next = NULL;
			pre->next = even;
		}
		else last->next = even;
		return odd;
    }
};