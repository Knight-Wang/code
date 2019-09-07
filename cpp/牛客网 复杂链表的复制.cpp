/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution
{
public:
    RandomListNode* clone(RandomListNode* pHead)
    {
        RandomListNode* p = pHead;
        while (p != NULL)
        {
            RandomListNode* tmp = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = tmp;
            p = tmp;
        }
        return pHead;
    }
    RandomListNode* connect(RandomListNode* pHead)
    {
        RandomListNode* p = pHead;
        while (p != NULL)
        {
            if (p->random != NULL) p->next->random = p->random->next;
            p = p->next->next;
        }
        return pHead;
    }
    RandomListNode* split(RandomListNode* pHead)
    {
        RandomListNode* res = NULL, *res_tail = NULL, *p = pHead, *tail = pHead;
        while (p != NULL)
        {
            RandomListNode* tmp = p->next->next;
            if (res == NULL) res = res_tail = p->next;
            else { res_tail->next = p->next; res_tail = res_tail->next; }
            tail->next = tmp; tail = tail->next;
            p = p->next;
        }
        return res;
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL) return NULL;
        pHead = clone(pHead);
        pHead = connect(pHead);
        return split(pHead);
    }
};