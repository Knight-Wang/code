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
    vector<int> p;
    void dfs(TreeNode* root, vector<int>& p, vector<string>& res)
    {
        if (root->left == NULL && root->right == NULL)
        {
            string tmp = "";
            for (auto it: p) { tmp += to_string(it); tmp += "->"; }
            tmp += to_string(root->val);
            res.push_back(tmp);
            return;
        }
        p.push_back(root->val);
        if (root->left) dfs(root->left, p, res);
        if (root->right) dfs(root->right, p, res);
        p.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<int> p;
        vector<string> res;
        if (root == NULL) return res;
        dfs(root, p, res);
        return res;
    }
};