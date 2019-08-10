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
    int pathSum(TreeNode* root, int sum)
    {
        if (root == NULL) return 0;
        int res = 0;
        res += count(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
    int count(TreeNode* root, int sum)
    {
        if (root == NULL) return 0;
        int res = 0;
        if (root->val == sum) res++;
        res += count(root->left, sum - root->val);
        res += count(root->right, sum - root->val);
        return res;
    }
};