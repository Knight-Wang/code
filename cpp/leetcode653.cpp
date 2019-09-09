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
    bool move_left(TreeNode* &root, stack<TreeNode*> &st)
    {
        if (root == NULL) return false;
        if (root->left == NULL && st.empty()) return false;
        if (root->left != NULL)
        {
            root = root->left;
            while (root->right != NULL) { st.push(root); root = root->right; }
        }
        else { root = st.top(); st.pop(); }
        return true;
    }
    bool move_right(TreeNode* &root, stack<TreeNode*> &st)
    {
        if (root == NULL) return false;
        if (root->right == NULL && st.empty()) return false;
        if (root->right != NULL)
        {
            root = root->right;
            while (root->left != NULL) { st.push(root); root = root->left; }
        }
        else { root = st.top(); st.pop(); }
        return true;
    }
    bool findTarget(TreeNode* root, int k)
    {
        if (root == NULL) return false;
        stack<TreeNode*> L, R;
        TreeNode* a = root, *b = root;
        while (a->left) { L.push(a); a = a->left; }
        while (b->right) { R.push(b); b = b->right; }
        while (a->val < b->val)
        {
            if (a->val + b->val > k)
            {
                if (!move_left(b, R)) return false;
            }
            else if (a->val + b->val < k)
            {
                if (!move_right(a, L)) return false;
            }
            else return true;
        }
        return false;
    }
};