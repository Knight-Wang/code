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
	void dfs(TreeNode* x, TreeNode* f, int d, unordered_map<TreeNode*, TreeNode*>& par, unordered_map<TreeNode*, int>& dep)
	{
		if (!x) return;
		dep[x] = d;
		par[x] = f;
		if (x->left)
			dfs(x->left, x, d + 1, par, dep);
		if (x->right)
			dfs(x->right, x, d + 1, par, dep);
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		unordered_map<TreeNode*, TreeNode*> par;
		unordered_map<TreeNode*, int> dep;
		dfs(root, NULL, 0, par, dep);
		int x = dep[p], y = dep[q];
		while (x > y)
		{
			p = par[p];
			x--;
		}
		while (y > x)
		{
			q = par[q];
			y--;
		}
		while (par[p] != par[q])
		{
			p = par[p];
			q = par[q];
		}
		return p == q ? p : par[p];
    }
};
