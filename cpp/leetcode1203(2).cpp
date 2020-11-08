class Solution
{
public:
    using pii = pair<int, int>;
    vector<int> toposort(vector<pii>& G)
    {
        unordered_map<int, int> id_map;
        int n = 0;
        for (auto& it: G)
        {
            if (!id_map.count(it.first)) id_map[it.first] = n++;
            if (!id_map.count(it.second)) id_map[it.second] = n++;
        }
        unordered_map<int, int> id_map_rev;
        for (auto& it: id_map) id_map_rev[it.second] = it.first;
        vector<int> ind(n, 0);
        vector<vector<int>> v(n, vector<int>());
        for (auto& it: G)
        {
            int x = id_map[it.first], y = id_map[it.second];
            ind[y]++;
            v[x].push_back(y);
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0) q.push(i);
        }
        vector<int> res;
        while (!q.empty())
        {
            int t = q.front(); q.pop();
            res.push_back(t);
            for (int i = 0; i < v[t].size(); i++)
            {
                int nt = v[t][i]; ind[nt]--;
                if (ind[nt] == 0) q.push(nt);
            }
        }
        if (res.size() != n) return vector<int>();
        for (int i = 0; i < n; i++) res[i] = id_map_rev[res[i]];
        return res;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
    {
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1) group[i] = m++;
        }
        vector<pii> among;
        unordered_map<int, vector<pii>> within;
        vector<int> ind(n, 0), outd(n, 0);
        for (int i = 0; i < beforeItems.size(); i++)
        {
            for (int j = 0; j < beforeItems[i].size(); j++)
            {
                int t = beforeItems[i][j];
                int x = group[i], y = group[t];
                if (x != y) among.push_back(make_pair(y, x));
                else
                {
                    if (!within.count(x)) within[x] = vector<pii>();
                    within[x].push_back(make_pair(t, i));
                    ind[i]++; outd[t]++;
                }
            }
        }
        unordered_map<int, unordered_set<int>> outlier;
        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0 && outd[i] == 0)
            {
                int g = group[i];
                if (!outlier.count(g)) outlier[g] = unordered_set<int>();
                outlier[g].insert(i);
            }
        }
        vector<int> tmp = toposort(among);
        if (!among.empty() && tmp.empty()) return vector<int>();
        unordered_set<int> st(tmp.begin(), tmp.end());
        for (auto& it: group)
        {
            if (!st.count(it))
            {
                st.insert(it);
                tmp.push_back(it);
            }
        }
        vector<int> res;
        for (auto& it: tmp)
        {
            vector<int> t = toposort(within[it]);
            if (t.empty() && !within[it].empty()) { res = vector<int>(); break; }
            res.insert(res.end(), t.begin(), t.end());
            for (auto& it1: outlier[it]) res.push_back(it1);
        }
        return res;
    }
};