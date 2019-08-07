#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
public:
    TreeNode* it;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root)
    {
        if (root == NULL) it = NULL;
        else
        {
            while (root->left) { st.push(root); root = root->left; }
            it = root;
        }
    }
    
    /** @return the next smallest number */
    int next()
    {
        TreeNode* tmp = it;
        if (it->right != NULL)
        {
            it = it->right;
            while (it->left != NULL) { st.push(it); it = it->left; }
        }
        else if (!st.empty()) { it = st.top(); st.pop(); }
        else it = NULL;
        return tmp->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return it != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    BSTIterator* iterator = new BSTIterator(root);
    cout << iterator->next() << endl;    // return 3
    cout << iterator->next() << endl;    // return 7
    iterator->hasNext(); // return true
    cout << iterator->next() << endl;    // return 9
    iterator->hasNext(); // return true
    cout << iterator->next() << endl;    // return 15
    iterator->hasNext(); // return true
    cout << iterator->next() << endl;    // return 20
    iterator->hasNext(); // return false
    return 0;
}