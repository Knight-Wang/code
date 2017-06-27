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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* fast = head, *slow = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (!fast)
        {
            ListNode* tmp = head->next;
            delete(head);
            return tmp;
        }
        else
        {
            while (fast->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
            ListNode* tmp = slow->next;
            slow->next = tmp->next;
            delete tmp;
            return head;
        }
    }
};