class Solution
{
public:
    bool match(TreeNode* root, vector<int>& v, int l, int r, vector<int>& res)
    {
        if (root == NULL) return l > r;
        if (root->val != v[l]) return false;
        if (root->left == NULL) return match(root->right, v, l + 1, r, res);
        else if (root->right == NULL) return match(root->left, v, l + 1, r, res);
        else
        {
            if (v[l + 1] == root->left->val)
            {
                int i = l + 2;
                while (i <= r && v[i] != root->right->val) i++;
                return match(root->left, v, l + 1, i - 1, res) && match(root->right, v, i, r, res);
            }
            else
            {
                res.push_back(v[l]);
                int i = l + 2;
                while (i <= r && v[i] != root->left->val) i++;
                return match(root->right, v, l + 1, i - 1, res) && match(root->left, v, i, r, res);
            }
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)
    {
        int n = voyage.size();
        vector<int> res;
        if (!match(root, voyage, 0, n - 1, res)) return vector<int>(1, -1);
        return res;
    }
};