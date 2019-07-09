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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2) return NULL;
        ListNode* a = l1, *b = l2, *res = NULL, *t = NULL;
        int c = 0;
        while (a || b)
        {
            int p = c;
            if (a) p += a->val; if (b) p += b->val;
            if (!res) { res = new ListNode(p % 10); t = res; }
            else { t->next = new ListNode(p % 10); t = t->next; }
            c = p / 10;
            if (a) a = a->next; if (b) b = b->next;
        }
        if (c) t->next = new ListNode(1);
        return res;
    }
};