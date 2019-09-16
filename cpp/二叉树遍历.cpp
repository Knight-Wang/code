#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left, *right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

void pre_order(TreeNode* root)
{
    if (root == NULL) return;
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(TreeNode* root)
{
    if (root == NULL) return;
    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}

void post_order(TreeNode* root)
{
    if (root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->val << " ";
}

void pre(TreeNode* root)
{
    stack<TreeNode*> st; st.push(NULL);
    while (root != NULL)
    {
        cout << root->val << " ";
        if (root->right != NULL) st.push(root->right);
        if (root->left != NULL) root = root->left;
        else
        {
            root = st.top(); st.pop();
        }
    }
}

void in(TreeNode* root)
{
    stack<TreeNode*> st;
    while (!st.empty() || root != NULL)
    {
        if (root != NULL)
        {
            st.push(root); root = root->left;
        }
        else
        {
            root = st.top(); st.pop();
            cout << root->val << " ";
            root = root->right;
        }
    }
}

void post(TreeNode* root)
{
    stack<pair<TreeNode*, bool>> st;
    while (!st.empty() || root != NULL)
    {
        while (root != NULL)
        {
            st.push(make_pair(root, false));
            root = root->left;
        }
        if (!st.top().second) { st.top().second = true; root = st.top().first->right; }
        else
        {
            cout << st.top().first->val << " "; st.pop();
            root = NULL;
        }
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->left->right->left->left = new TreeNode(9);
    root->left->right->left->right = new TreeNode(10);
    pre_order(root);
    cout << endl;
    pre(root);
    cout << endl << "+++" << endl;
    in_order(root);
    cout << endl;
    in(root);
    cout << endl << "---" << endl;
    post_order(root);
    cout << endl;
    post(root);
    cout << endl << "***" << endl;
    return 0;
}