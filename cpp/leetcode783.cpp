/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void in_order(TreeNode* root)
    {
        if (!root) return;
        in_order(root->left);
        v.push_back(root->val);
        in_order(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        in_order(root);
        int minn = v[1] - v[0];
        for (int i = 1; i < v.size() - 1; i++) 
            minn = min(minn, v[i + 1] - v[i]);
        return minn;
    }
};