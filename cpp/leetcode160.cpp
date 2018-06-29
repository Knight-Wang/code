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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode * a = headA, * b = headB;
        while (a && b) { a = a->next; b = b->next; }
        if (!a) 
        { 
            a = headB; 
            while (b) { b = b->next; a = a->next; }
            b = headA;
        }
        else 
        { 
            b = headA; 
            while (a) { a = a->next; b = b->next; }
            a = headB;
        }
        while (a && b) { if (a == b) return a; a = a->next; b = b->next; }
        return NULL;
    }
};