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
    bool dfs(TreeNode * a, TreeNode * b)
    {
        if (!a && !b) return true;
        if ((!a && b ) || (a && !b)) return false;
        if (a->val != b->val) return false;
        if (!dfs(a->left, b->right) || !dfs(a->right, b->left)) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
};