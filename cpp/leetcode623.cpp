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
    void dfs(TreeNode* root, int cur, int v, int d)
    {
        if (root == NULL || cur > d - 1) return;
        if (cur == d - 1)
        {
            TreeNode* tmp = root->left;
            root->left = new TreeNode(v);
            root->left->left = tmp;
            tmp = root->right;
            root->right = new TreeNode(v);
            root->right->right = tmp;
            return;
        }
        dfs(root->left, cur + 1, v, d);
        dfs(root->right, cur + 1, v, d);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if (d == 1)
        {
            TreeNode* res = new TreeNode(v);
            res->left = root;
            return res;
        }
        else
        {
            dfs(root, 1, v, d);
            return root;
        }
    }
};