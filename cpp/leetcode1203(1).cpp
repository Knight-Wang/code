class Solution
{
public:
    using pii = pair<int, int>;
    const int INF = 0x3f3f3f3f;
    vector<int> toposort(vector<vector<int>>& G, unordered_map<int, int>& mp)
    {
        int n = G.size();
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < G[i].size(); j++)
            {
                int t = G[i][j]; ind[t]++;
            }
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0) q.push(make_pair(mp[i], i));
        }
        vector<int> res;
        while (!q.empty())
        {
            pair<int, int> t = q.top(); q.pop();
            int p = t.second;
            res.push_back(p);
            for (int i = 0; i < G[p].size(); i++)
            {
                int nt = G[p][i]; ind[nt]--;
                if (ind[nt] == 0) q.push(make_pair(mp[nt], nt));
            }
        }
        if (res.size() != n) return vector<int>();
        return res;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
    {
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1) group[i] = m++;
        }
        vector<vector<int>> G(m, vector<int>()), g(n, vector<int>());
        for (int i = 0; i < beforeItems.size(); i++)
        {
            for (int j = 0; j < beforeItems[i].size(); j++)
            {
                int t = beforeItems[i][j];
                int x = group[i], y = group[t];
                if (x != y) G[y].push_back(x);
                g[t].push_back(i);
            }
        }
        unordered_map<int, int> _;
        vector<int> res = toposort(G, _);
        if (res.empty()) return vector<int>();
        unordered_map<int, int> gmp;
        for (int i = 0; i < res.size(); i++) gmp[res[i]] = i;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int g = group[i];
            if (g != -1) mp[i] = gmp[g];
            else mp[i] = INF;
        }
        return toposort(g, mp);
    }
};