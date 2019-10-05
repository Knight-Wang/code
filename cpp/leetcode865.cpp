class Solution
{
public:
    pair<TreeNode*, int> work(TreeNode* root)
    {
        if (root == NULL) return make_pair((TreeNode*)NULL, 0);
        auto l = work(root->left);
        auto r = work(root->right);
        TreeNode* res = NULL;
        if (l.second > r.second) res = l.first;
        else if (l.second < r.second) res = r.first;
        else res = root;
        return make_pair(res, max(l.second, r.second) + 1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        auto res = work(root);
        return res.first;
    }
};