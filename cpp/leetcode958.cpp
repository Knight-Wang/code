class Solution
{
public:
    bool isCompleteTree(TreeNode* root)
    {
        vector<TreeNode*> cur; cur.push_back(root);
        bool flg = false;
        while (!cur.empty())
        {
            
            vector<TreeNode*> nxt;
            for (auto it: cur)
            {
                if ((it->left || it->right) && flg) return false;
                if (it->left) nxt.push_back(it->left);
                else flg = true;
                if (it->right)
                {
                    nxt.push_back(it->right);
                    if (it->left == NULL) return false;
                }
                else flg = true;
            }
            cur = nxt;
        }
        return true;
    }
};