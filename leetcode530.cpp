// leetcode530.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
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
	void inOrder(TreeNode * root, vector<int> & res)
	{
		if (!root)
			return;
		inOrder(root->left, res);
		res.push_back(root->val);
		inOrder(root->right, res);	
	}
	int getMinimumDifference(TreeNode* root)
	{
		vector<int> res;
		inOrder(root, res);
		int n = res.size();
		int minn = 0x3f3f3f3f;
		for (int i = 0; i < n - 1; i++)
		{
			if (res[i + 1] - res[i] < minn)
				minn = res[i + 1] - res[i];
		}
		return minn;
	}
};
int main()
{
	Solution s;
	TreeNode * root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	cout << s.getMinimumDifference(root);
	system("pause");
	return 0;
}

