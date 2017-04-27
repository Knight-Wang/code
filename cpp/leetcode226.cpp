// leetcode226.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
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
	TreeNode* invertTree(TreeNode* root) 
	{
		if (root == NULL)
			return NULL;
		TreeNode * tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		if (root->left != NULL)
		{
		    invertTree(root->left);
		}
		if (root->right != NULL)
		{
			invertTree(root->right);
		}
		return root;
	}
	void dfs(TreeNode * root)
	{
		cout << root->val << " ";
		if (root->left)
			dfs(root->left);
		if (root->right)
			dfs(root->right);
	}
};

int main()
{
	TreeNode * root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);
	Solution s;
	s.dfs(root);
	s.invertTree(root);
	puts("");
	s.dfs(root);
	system("pause");
	return 0;
}

