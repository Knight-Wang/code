/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution
{
public:

    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* pre = NULL, *cur = pHead;
        while (cur != NULL)
        {
            bool flg = false;
            while (cur->next != NULL && cur->next->val == cur->val)
            {
                ListNode* tmp = cur;
                cur = cur->next;
                tmp->next = NULL;
                if (pHead == tmp) pHead = NULL;
                delete tmp;
                flg = true;
            }
            if (flg)
            {
                ListNode* tmp = cur; cur = cur->next;
                tmp->next = NULL; delete tmp;
            }
            else
            {
                if (pre == NULL) pHead = pre = cur;
                else { pre->next = cur; pre = pre->next; }
                cur = cur->next;
                pre->next = NULL;
            }
        }
        return pHead;
    }
};