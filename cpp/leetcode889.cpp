class Solution
{
public:
    TreeNode* work(vector<int>& pre, int l, int r, vector<int>& post, int L, int R)
    {
        if (l > r) return NULL;
        TreeNode* res = new TreeNode(pre[l]);
        if (l == r) return res;
        int i = R - 1;
        while (post[i] != pre[l + 1]) i--;
        int len_l = i - L + 1, len_r = R - i;
        res->left = work(pre, l + 1, l + len_l, post, L, i);
        res->right = work(pre, l + len_l + 1, r, post, i + 1, R);
        return res;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
    {
        int n = pre.size();
        return work(pre, 0, n - 1, post, 0, n - 1);
    }
};