class Solution
{
public:
    pair<TreeNode*, int> dfs(TreeNode* root)
    {
        if (root == NULL) return make_pair((TreeNode*)NULL, 0);
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        TreeNode* res = NULL; int d = max(l.second, r.second) + 1;
        if (l.second > r.second) res = l.first;
        else if (l.second < r.second) res = r.first;
        else res = root;
        return make_pair(res, d);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        pair<TreeNode*, int> res = dfs(root);
        return res.first;
    }
};