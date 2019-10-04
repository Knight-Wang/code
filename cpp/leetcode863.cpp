class Solution
{
public:
    void dfs(TreeNode* root, TreeNode* p, unordered_map<int, vector<int>>& G)
    {
        if (root == NULL) return;
        if (root && p)
        {
            int a = root->val, b = p->val;
            if (!G.count(a)) G[a] = vector<int>();
            G[a].push_back(b);
            if (!G.count(b)) G[b] = vector<int>();
            G[b].push_back(a);
        }
        dfs(root->left, root, G);
        dfs(root->right, root, G);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
        unordered_map<int, vector<int>> G;
        dfs(root, NULL, G);
        unordered_set<int> vis;
        queue<pair<int, int>> q;
        q.push(make_pair(target->val, 0)); vis.insert(target->val);
        vector<int> res;
        while (!q.empty())
        {
            pair<int, int> tmp = q.front(); q.pop();
            if (tmp.second == K) res.push_back(tmp.first);
            if (tmp.second > K) break;
            for (auto it: G[tmp.first])
            {
                if (!vis.count(it))
                {
                    q.push(make_pair(it, tmp.second + 1));
                    vis.insert(it);
                }
            }
        }
        return res;
    }
};