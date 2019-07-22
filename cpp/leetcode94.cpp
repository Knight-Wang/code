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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while (tmp || !s.empty())
        {
            if (tmp) { s.push(tmp); tmp = tmp->left; }
            else
            {
                tmp = s.top(); s.pop(); res.push_back(tmp->val); tmp = tmp->right;
            }
        }
        return res;
    }
};