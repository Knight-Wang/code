/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isEvenOddTree(TreeNode* root)
    {
        vector<TreeNode*> cur, nxt;
        cur.push_back(root);
        int l = 0;
        bool flg = true;
        while (!cur.empty())
        {
            int n = cur.size();
            for (int i = 0; i < n; i++)
            {
                if (l % 2 == 1)
                {
                    if (cur[i]->val % 2 == 1) flg = false;
                    else if (i + 1 < n && cur[i]->val <= cur[i + 1]->val) flg = false;
                    if (!flg) break;
                }
                else
                {
                    if (cur[i]->val % 2 == 0) flg = false;
                    else if (i + 1 < n && cur[i]->val >= cur[i + 1]->val) flg = false;
                    if (!flg) break;
                }
                if (cur[i]->left) nxt.push_back(cur[i]->left);
                if (cur[i]->right) nxt.push_back(cur[i]->right);
            }
            if (!flg) break;
            cur = nxt; nxt.clear(); l++;
        }
        return flg;
    }
};
