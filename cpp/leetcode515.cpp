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
    void dfs(TreeNode* root, int d, vector<int>& res)
    {
        if (root == NULL) return;
        if (res.size() > d) res[d] = max(res[d], root->val);
        else res.push_back(root->val);
        dfs(root->left, d + 1, res); dfs(root->right, d + 1, res);
    }
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};