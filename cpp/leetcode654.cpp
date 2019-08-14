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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        stack<TreeNode*> st;
        for (auto it: nums)
        {
            TreeNode* tmp = new TreeNode(it), *last = NULL;
            while (!st.empty() && tmp->val > st.top()->val)
            {
                last = st.top(); st.pop();
            }
            tmp->left = last;
            if (!st.empty()) st.top()->right = tmp;
            st.push(tmp);
        }
        TreeNode* res = NULL;
        while (!st.empty())
        {
            res = st.top(); st.pop();
        }
        return res;
    }
};