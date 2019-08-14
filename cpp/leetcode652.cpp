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
    string dfs(TreeNode* root, unordered_map<string, int>& cnt, vector<TreeNode*>& res)
    {
        if (root == NULL) return "";
        string ans = to_string(root->val);
        ans += "(" + dfs(root->left, cnt, res) + ")";
        ans += "(" + dfs(root->right, cnt, res) + ")";
        if (!cnt.count(ans)) cnt[ans] = 0;
        else if (cnt[ans] == 1) res.push_back(root);
        cnt[ans]++;
        return ans;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        unordered_map<string, int> mp;
        vector<TreeNode*> res;
        dfs(root, mp, res);
        return res;
    }
};