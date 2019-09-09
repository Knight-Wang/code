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
    int height(TreeNode* root)
    {
        if (root == NULL) return 0;
        return height(root->left) + 1;
    }
    int countNodes(TreeNode* root)
    {
        if (root == NULL) return 0;
        int h = height(root->left);
        int r = height(root->right);
        if (r == h - 1) return (1 << h - 1) + countNodes(root->left);
        else return (1 << h) + countNodes(root->right);
    }
};