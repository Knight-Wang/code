class Solution
{
public:
    vector<int> toposort(vector<vector<int>>& G, unordered_set<int>& v)
    {
        unordered_map<int, int> ind;
        for (auto& it: v)
        {
            for (int i = 0; i < G[it].size(); i++)
            {
                int s = G[it][i];
                if (v.count(s)) ind[s]++;
            }
        }
        queue<int> q;
        for (auto& it: v)
        {
            if (ind[it] == 0) q.push(it);
        }
        vector<int> res;
        while (!q.empty())
        {
            int t = q.front(); q.pop();
            res.push_back(t);
            for (int i = 0; i < G[t].size(); i++)
            {
                int s = G[t][i];
                if (v.count(s))
                {
                    ind[s]--;
                    if (ind[s] == 0) q.push(s);
                }
            }
        }
        if (res.size() != v.size()) return vector<int>();
        return res;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
    {
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1) group[i] = m++;
        }
        vector<unordered_set<int>> gvc(m, unordered_set<int>());
        for (int i = 0; i < n; i++) gvc[group[i]].insert(i);
        vector<vector<int>> among(m, vector<int>()), rev(n, vector<int>());
        for (int i = 0; i < beforeItems.size(); i++)
        {
            for (int j = 0; j < beforeItems[i].size(); j++)
            {
                int t = beforeItems[i][j];
                int x = group[i], y = group[t];
                if (x != y) among[y].push_back(x);
                rev[t].push_back(i);
            }
        }
        unordered_set<int> gst{group.begin(), group.end()};
        vector<int> group_res = toposort(among, gst);
        if (group_res.empty()) return group_res;
        vector<int> res;
        for (auto& it: group_res)
        {
            vector<int> t = toposort(rev, gvc[it]);
            if (t.empty()) return t;
            res.insert(res.end(), t.begin(), t.end());
        }
        return res;
    }
};