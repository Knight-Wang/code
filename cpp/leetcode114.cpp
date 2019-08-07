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
    void work(TreeNode* root)
    {
        if (root == NULL) return;
        work(root->left); work(root->right);
        if (root->left == NULL) return;
        TreeNode* tmp = root->left;
        while (tmp->right != NULL) tmp = tmp->right;
        tmp->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    void flatten(TreeNode* root)
    {
        work(root);
    }
};