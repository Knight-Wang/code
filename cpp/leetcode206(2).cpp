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
        if (head == NULL || head->next == NULL) return head;
        ListNode* a = head, *b = head->next, *c = head->next->next;
        head->next = NULL;
        while (true)
        {
            b->next = a;
            if (c == NULL) break;
            a = b; b = c; c = c->next;
        }
        return b;
    }
};