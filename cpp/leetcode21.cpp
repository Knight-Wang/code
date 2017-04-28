/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode * s1 = l1, * s2 = l2, * res = NULL, * tail = NULL;
        while (s1 && s2)
        {
            if (!tail) 
            {
                tail = new ListNode(0);
                res = tail;
            }
            else
            {
                tail->next = new ListNode(0);
                tail = tail->next;
            }
            if (s1->val < s2->val) 
            {
                tail->val = s1->val;
                s1 = s1->next;
            }
            else 
            {
                tail->val = s2->val;
                s2 = s2->next;
            }
        }
        if (s1)
        {
            while (s1)
            {
                tail->next = new ListNode(s1->val);
                tail = tail->next;
                s1 = s1->next;
            }
        }
        if (s2)
        {
            while (s2)
            {
                tail->next = new ListNode(s2->val);
                tail = tail->next;
                s2 = s2->next;
            }
        }
        return res;
    }
};