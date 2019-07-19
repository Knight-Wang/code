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
    bool check(TreeNode* root, long long& maxn)
    {
        if (!root) return true;
        if (root->left && !check(root->left, maxn)) return false;
        if (root->val <= maxn) return false;
        maxn = root->val;
        return check(root->right, maxn);
    }
    bool isValidBST(TreeNode* root)
    {
        long long maxn = INT_MIN - 1ll;
        return check(root, maxn);
    }
};