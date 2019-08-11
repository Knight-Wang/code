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
    void inOrder(TreeNode* root, int& sum)
    {
        if (root == NULL) return;
        inOrder(root->right, sum);
        root->val = sum += root->val;
        inOrder(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) 
    {
        int sum = 0;
        inOrder(root, sum);
        return root;
    }
};