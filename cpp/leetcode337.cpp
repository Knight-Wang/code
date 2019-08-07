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
    pair<int, int> dfs(TreeNode* root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return pair<int, int>(0, root->val);
        }
        int x = 0, y = root->val;
        if (root->left)
        {
            pair<int, int> l = dfs(root->left);
            x += max(l.first, l.second);
            y += l.first;
        }
        if (root->right)
        {
            pair<int, int> r = dfs(root->right);
            x += max(r.first, r.second);
            y += r.first;
        }
        return pair<int, int>(x, y);
    }
    int rob(TreeNode* root)
    {
        if (root == NULL) return 0;
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }
};