/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* a = root, *b = root, *res = root;
        while (a != p && b != q)
        {
            if (a->val > p->val) a = a->left;
            else a = a->right;
            if (b->val > q->val) b = b->left;
            else b = b->right;
            if (a == b) res = a;
        }
        return res;
    }
};