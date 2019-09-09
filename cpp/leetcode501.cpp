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
    void work(TreeNode* root, int &maxn, int &cur_val, int &curn)
    {
        if (root == NULL) return;
        work(root->left, maxn, cur_val, curn);
        if (root->val != cur_val)
        {
            if (curn > maxn) maxn = curn;
            cur_val = root->val;
            curn = 1;
        }
        else curn++;
        work(root->right, maxn, cur_val, curn);
    }
    void find(TreeNode* root, int &maxn, int &cur_val, int &curn, vector<int>& res)
    {
        if (root == NULL) return;
        find(root->left, maxn, cur_val, curn, res);
        if (root->val != cur_val)
        {
            if (curn == maxn) res.push_back(cur_val);
            cur_val = root->val; curn = 1;
        }
        else curn++;
        find(root->right, maxn, cur_val, curn, res);
    }
    vector<int> findMode(TreeNode* root)
    {
        int maxn = 1, cur_val = 0, curn = 0;
        work(root, maxn, cur_val, curn);
        maxn = max(maxn, curn);
        cur_val = curn = 0;
        vector<int> res;
        find(root, maxn, cur_val, curn, res);
        if (curn ==  maxn) res.push_back(cur_val);
        return res;
    }
};