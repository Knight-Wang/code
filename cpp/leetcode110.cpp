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
    int dfs(TreeNode* root, bool& flg)
    {
        if (!root) return 0;
        int x = dfs(root->left, flg), y = dfs(root->right, flg);
        if (abs(x - y) > 1) flg = false;
        return max(x, y) + 1;
    }
    bool isBalanced(TreeNode* root)
    {
        bool flg = true;
        dfs(root, flg);
        return flg;
    }
};