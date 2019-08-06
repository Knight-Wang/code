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
    void dfs(TreeNode* root, int cur, int sum, vector<int>& p, vector<vector<int>>& res)
    {
        p.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (cur + root->val == sum)
            {
                vector<int> tmp(p.begin(), p.end());
                res.push_back(tmp);
            }
        }
        if (root->left) dfs(root->left, cur + root->val, sum, p, res);
        if (root->right) dfs(root->right, cur + root->val, sum, p, res);
        p.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<int> p;
        vector<vector<int>> res;
        if (root) dfs(root, 0, sum, p, res);
        return res;
    }
};