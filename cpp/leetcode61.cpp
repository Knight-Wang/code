/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head) return NULL;
        int n = 0;
        ListNode * tmp = head;
        while (tmp)
        {
            n++; tmp = tmp->next;
        }
        k %= n;
        if (!k) return head;
        tmp = head;
        for (int i = 0; i < n - k - 1; i++) tmp = tmp->next;
        ListNode * new_head = tmp->next;
        tmp->next = NULL;
        tmp = new_head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = head;
        return new_head;
    }
};