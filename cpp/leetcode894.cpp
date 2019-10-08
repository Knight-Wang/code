class Solution
{
public:
    TreeNode* copy(TreeNode* root)
    {
        if (root == NULL) return NULL;
        TreeNode* res = new TreeNode(root->val);
        res->left = copy(root->left);
        res->right = copy(root->right);
        return res;
    }
    vector<TreeNode*> allPossibleFBT(int N)
    {
        vector<vector<TreeNode*>> t(N + 1, vector<TreeNode*>());
        TreeNode* tmp = new TreeNode(0);
        t[1].push_back(tmp);
        for (int i = 3; i <= N; i += 2)
        {
            for (int j = 1; j < i - 1; j++)
            {
                TreeNode* l = NULL, *r = NULL;
                for (int k = 0; k < t[j].size(); k++)
                {
                    l = copy(t[j][k]);
                    for (int p = 0; p < t[i - j - 1].size(); p++)
                    {
                        r = copy(t[i - j - 1][p]);
                        if (l == NULL || r == NULL) continue;
                        TreeNode* tmp = new TreeNode(0);
                        tmp->left = l; tmp->right = r;
                        t[i].push_back(tmp);        
                    }
                }
            }
        }
        return t[N];
    }
};