#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	int dfs(TreeNode* root, vector<int>& v)
	{
		if (root == NULL) return 0;
		int l = dfs(root->left, v);
		int r = dfs(root->right, v);
		int ans = root->val, tmp = max(l, r);
		if (tmp > 0) ans += tmp;
		int sum = root->val;
		if (l > 0) sum += l;
		if (r > 0) sum += r;
		v.push_back(sum);
		return ans;
	}
    int maxPathSum(TreeNode* root)
    {
    	vector<int> v;
		dfs(root, v);
		return *max_element(v.begin(), v.end());
    }
};

int main()
{
	TreeNode* root = new TreeNode(-10);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	cout << Solution().maxPathSum(root) << endl;
	return 0;
}