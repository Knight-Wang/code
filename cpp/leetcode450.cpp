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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        TreeNode* p = root, *f = NULL;
        while (p != NULL)
        {
            if (p->val == key) break;
            else
            {
                f = p;
                if (p->val > key) p = p->left;
                else p = p->right;
            }
        }
        if (p == NULL) return root;
        if (p->left == NULL)
        {
            if (f == NULL) { TreeNode* ans = root->right; delete p; return ans; }
            if (p == f->left) f->left = p->right;
            else f->right = p->right;
            delete p;
        }
        else
        {
            TreeNode* m = p->left, *n = p;
            while (m->right != NULL) { n = m; m = m->right; }
            swap(m->val, p->val);
            if (m == n->left) n->left = m->left;
            else n->right = m->left;
            delete(m);
        }
        return root;
    }
};