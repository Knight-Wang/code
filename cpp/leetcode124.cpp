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
    int dfs(TreeNode* root, int& maxn)
    {
        if (!root) return 0;
        int x = dfs(root->left, maxn);
        int y = dfs(root->right, maxn);
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        maxn = max(maxn, x + y + root->val);
        return max(x, y) + root->val;
    }
    int maxPathSum(TreeNode* root)
    {
        int maxn = INT_MIN;
        dfs(root, maxn);
        return maxn;
    }
};