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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res; stack<TreeNode*> s;
        TreeNode* tmp = root;
        while (tmp)
        {
            res.push_back(tmp->val);
            if (tmp->right != NULL) s.push(tmp->right);
            if (tmp->left != NULL) tmp = tmp->left;
            else if (!s.empty()) { tmp = s.top(); s.pop(); }
            else break;
        }
        return res;
    }
};