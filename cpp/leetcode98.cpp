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
    bool isValidBST(TreeNode* root)
    {
        return dfs(root, -0x3f3f3f3f3f3f3f3fLL, 0x3f3f3f3f3f3f3f3fLL);
    }
    bool dfs(TreeNode* root, long long minn, long long maxn)
    {
        if (!root) return true;
        if (root->val <= minn || root->val >= maxn) return false;
        if (root->left && root->left->val >= root->val) return false;
        if (root->right && root->right->val <= root->val) return false;
        return dfs(root->left, minn, root->val) && dfs(root->right, root->val, maxn);
    }
};

int main()
{
    TreeNode * root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(20);
    cout << Solution().isValidBST(root) << endl;
    return 0;
}