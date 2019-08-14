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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == NULL || t2 == NULL)
        {
            if (t1 == t2) return NULL;
            else if (t1) return t1;
            else return t2;
        }
        TreeNode* res = new TreeNode(t1->val + t2->val);
        res->left = mergeTrees(t1->left, t2->left);
        res->right = mergeTrees(t1->right, t2->right);
        return res;
    }
};