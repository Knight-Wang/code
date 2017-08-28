/**
 * Definition for a binary tree node.
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
	vector<TreeNode *> dfs(int l, int r)
	{
		vector<TreeNode *> ret;
		if (l > r) 
		{
			ret.push_back(NULL);
			return ret;
		}
		if (l == r) 
		{
			ret.push_back(new TreeNode(l));
			return ret;
		}
		for (int i = l; i <= r; i++)
		{
			vector<TreeNode *> lc = dfs(l, i - 1);
			vector<TreeNode *> rc = dfs(i + 1, r);
			for (auto j : lc)
			{
				for (auto k : rc)
				{
					TreeNode * tmp = new TreeNode(i);
					tmp->left = j; tmp->right = k;
					ret.push_back(tmp);
				}
			}
		}
		return ret;
	}
    vector<TreeNode *> generateTrees(int n) 
    {
        if (!n) return vector<TreeNode *>();
		return dfs(1, n);
    }
};