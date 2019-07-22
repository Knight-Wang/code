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
    vector<int> postorderTraversal(TreeNode* root)
    {
        TreeNode* tmp = root; stack<pair<TreeNode*, bool>> s;
        vector<int> res;
        while (tmp || !s.empty())
        {
            if (tmp) { s.push(make_pair(tmp, false)); tmp = tmp->left; }
            else
            {
                if (s.top().second) { res.push_back(s.top().first->val); s.pop(); }
                else { s.top().second = true; tmp = s.top().first->right; }
            }
        }
        return res;
    }
};