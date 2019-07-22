#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node* left, *right;
    node(int x):val(x),left(NULL),right(NULL) {}
};

vector<int> pre_order(node* root, int key)
{
    stack<node*> s; vector<node*> p;
    node* tmp = root;
    while (tmp)
    {
        p.push_back(tmp);
        if (tmp->val == key) break;
        if (tmp->right != NULL) s.push(tmp->right);
        if (tmp->left) tmp = tmp->left;
        else if (!s.empty())
        {
            while (!p.empty() && p.back()->right != s.top()) p.pop_back();
            tmp = s.top(); s.pop();
        }
        else break;
    }
    vector<int> res;
    for (auto it: p) res.push_back(it->val);
    return res;
}

int main()
{
    node* root = new node(3);
    root->left = new node(5);
    root->left->left = new node(7);
    root->left->right = new node(8);
    root->left->right->left = new node(6);
    root->right = new node(2);
    root->right->right = new node(9);
    root->right->right->right = new node(1);
    vector<int> res = pre_order(root, 6);
    for (auto it: res) cout << it << " ";
    cout << endl;
    return 0;
}