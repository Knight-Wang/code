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
    bool check(TreeNode* a, TreeNode* b)
    {
        if (a == NULL || b == NULL) return a == b;
        if (a->val != b->val) return false;
        return check(a->left, b->left) && check(a->right, b->right);
    }
    bool dfs(TreeNode* x, TreeNode* y)
    {
        if (x == NULL) return false;
        if (check(x, y)) return true;
        return dfs(x->left, y) || dfs(x->right, y);
    }
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if (t == NULL) return true;
        return dfs(s, t);
    }
};