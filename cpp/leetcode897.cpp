class Solution
{
public:
    pair<TreeNode*, TreeNode*> work(TreeNode* root)
    {
        TreeNode* tail = root;
        if (root->right != NULL)
        {
            pair<TreeNode*, TreeNode*> r = work(root->right);
            tail = r.second;
            root->right = r.first;
        }
        if (root->left == NULL) return make_pair(root, tail);
        pair<TreeNode*, TreeNode*> l = work(root->left);
        l.second->right = root; root->left = NULL;
        return make_pair(l.first, tail);
    }
    TreeNode* increasingBST(TreeNode* root)
    {
        if (root == NULL) return NULL;
        pair<TreeNode*, TreeNode*> tmp = work(root);
        return tmp.first;
    }
};