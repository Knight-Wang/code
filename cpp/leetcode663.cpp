#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	unordered_map<TreeNode *, int> treeSum;
	int dfs(TreeNode * root)
	{
		if (!root) return 0;
		int sum = root->val;
		sum += dfs(root->left);
		sum += dfs(root->right);
		return treeSum[root] = sum;
	}
	bool check(TreeNode * root, int total)
	{
		if (!root) return false;
		if (root->left && treeSum[root->left] == total - treeSum[root->left])
			return true;
		if (root->right && treeSum[root->right] == total - treeSum[root->right])
			return true;
		bool flg = false;
		flg |= check(root->left, total);
		flg |= check(root->right, total);
		return flg;
	}	
    bool checkEqualTree(TreeNode* root) 
    {
		if (!root) return false;
        dfs(root);
		int total = treeSum[root];
		return check(root, total);
    }
};

int main()
{
	Solution s;
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(10);
	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(20);
	cout << s.checkEqualTree(root) << endl;
	return 0;
}