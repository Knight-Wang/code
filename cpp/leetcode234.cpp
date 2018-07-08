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
    bool isPalindrome(ListNode* head) 
    {
        vector<int> v;
        ListNode * tmp = head;
        while (tmp)
        {
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        int l = 0, r = (int)v.size() - 1;
        while (l < r)
        {
            if (v[l] != v[r]) return false;
            l++; r--;
        }
        return true;
    }
};