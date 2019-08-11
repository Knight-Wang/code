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
    int dfs(TreeNode* root, unordered_map<int, int>& mp, int& maxn)
    {
        if (root == NULL) return 0;
        int x = dfs(root->left, mp, maxn), y = dfs(root->right, mp, maxn);
        int sum = x + y + root->val;
        if (!mp.count(sum)) mp[sum] = 0;
        mp[sum]++;
        maxn = max(maxn, mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        unordered_map<int, int> mp; int maxn = 0;
        dfs(root, mp, maxn);
        vector<int> v;
        for (auto it: mp)
        {
            if (it.second == maxn) v.push_back(it.first);
        }
        return v;
    }
};