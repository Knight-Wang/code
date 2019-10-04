class Solution
{
public:
    void dfs(int root, int p, vector<vector<int>>& G, vector<int>& cnt, vector<int>& res)
    {
        for (auto it: G[root])
        {
            if (it == p) continue;
            dfs(it, root, G, cnt, res);
            cnt[root] += cnt[it];
            res[root] += res[it] + cnt[it];
        }
        cnt[root]++;
    }
    void dfs2(int root, int p, vector<vector<int>>& G, vector<int>& cnt, vector<int>& res, int N)
    {
        for (auto it: G[root])
        {
            if (it == p) continue;
            res[it] = res[root] - cnt[it] + N - cnt[it];
            dfs2(it, root, G, cnt, res, N);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges)
    {
        vector<vector<int>> G(N, vector<int>());
        for (auto it: edges)
        {
            int a = it[0], b = it[1];
            G[a].push_back(b); G[b].push_back(a);
        }
        vector<int> cnt(N, 0), res(N, 0);
        dfs(0, -1, G, cnt, res);
        dfs2(0, -1, G, cnt, res, N);
        return res;
    }
};