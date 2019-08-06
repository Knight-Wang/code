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
    bool check(TreeNode* root, int cur, int sum)
    {
        if (root->left == NULL && root->right == NULL) return cur + root->val == sum;
        bool res = false;
        if (root->left) res |= check(root->left, cur + root->val, sum);
        if (root->right) res |= check(root->right, cur + root->val, sum);
        return res;
    }
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (root == NULL) return false;
        return check(root, 0, sum);
    }
};