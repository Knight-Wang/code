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
    bool check(TreeNode* root, int &res, int &maxn, int &minn, int &cnt)
    {
        if (root->left == NULL && root->right == NULL)
        {
            maxn = minn = root->val; cnt = 1; res = max(res, cnt);
            return true;
        }
        int max_l = INT_MIN, min_l = INT_MAX, cnt_l = 0;
        int max_r = INT_MIN, min_r = INT_MAX, cnt_r = 0;
        bool flg = true;
        if (root->left != NULL && !check(root->left, res, max_l, min_l, cnt_l)) flg = false;
        if (root->right != NULL && !check(root->right, res, max_r, min_r, cnt_r)) flg = false;
        if (!flg || root->val <= max_l || root->val >= min_r) return false;
        minn = min(min_l, root->val); maxn = max(root->val, max_r); cnt = cnt_l + cnt_r + 1;
        res = max(res, cnt);
        return true;
    }
    int largestBSTSubtree(TreeNode* root)
    {
        if (root == NULL) return 0;
        int res = 0, maxn = INT_MIN, minn = INT_MAX, cnt = 0;
        check(root, res, maxn, minn, cnt);
        return res;
    }
};