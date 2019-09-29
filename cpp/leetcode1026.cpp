class Solution
{
public:
    pair<int, int> dfs(TreeNode* root, int& res)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return pair<int, int>(root->val, root->val);
        }
        int minn = root->val, maxn = root->val;
        if (root->left)
        {
            auto l = dfs(root->left, res);
            minn = min(minn, l.first); maxn = max(maxn, l.second);
        }
        if (root->right)
        {
            auto r = dfs(root->right, res);
            minn = min(minn, r.first); maxn = max(maxn, r.second);
        }
        if (minn != INT_MAX) res = max(res, abs(root->val - minn));
        if (maxn != INT_MIN) res = max(res, abs(root->val - maxn));
        return pair<int, int>(minn, maxn);
    }
    int maxAncestorDiff(TreeNode* root)
    {
        int res = 0;
        dfs(root, res);
        return res;
    }
};