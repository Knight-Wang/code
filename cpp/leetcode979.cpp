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
    int ans = 0;
    int dfs(TreeNode* root)
    {
        if (!root) return 0; //n_coins - n_nodes
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans += abs(l) + abs(r);
        return l + r + root->val - 1;
    }
    int distributeCoins(TreeNode* root)
    {
        dfs(root);
        return ans;
    }
};