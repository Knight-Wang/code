class Solution
{
public:
    void work(TreeNode* root, TreeNode* p, set<int>& st, vector<TreeNode*>& res)
    {
        if (root == NULL) return;
        work(root->left, root, st, res);
        work(root->right, root, st, res);
        if (st.count(root->val))
        {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            root->left = root->right = NULL;
            if (p)
            {
                if (root == p->left) p->left = NULL;
                else p->right = NULL;
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        work(root, NULL, st, res);
        if (!st.count(root->val)) res.push_back(root);
        return res;
    }
};