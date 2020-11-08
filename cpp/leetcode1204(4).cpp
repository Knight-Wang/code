class Solution
{
public:
    inline vector<int> toposort_item(vector<int>& group_res, vector<unordered_set<int>>& gvc, 
        vector<vector<int>>& G)
    {
        int n = G.size();
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < G[i].size(); j++)
            {
                int s = G[i][j]; ind[s]++;
            }
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < group_res.size(); i++)
        {
            vector<int> tmp;
            for (auto& it: gvc[group_res[i]])
            {
                if (ind[it] == 0) q.push(it);
            }
            while (!q.empty())
            {
                int t = q.front(); q.pop();
                tmp.push_back(t);
                for (int i = 0; i < G[t].size(); i++)
                {
                    int s = G[t][i]; ind[s]--;
                    if (ind[s] == 0) q.push(s);
                }
            }
            if (tmp.size() != gvc[group_res[i]].size()) return vector<int>();
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }
    vector<int> toposort_group(vector<vector<int>>& G)
    {
        int m = G.size();
        vector<int> ind(m, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < G[i].size(); j++)
            {
                int s = G[i][j]; ind[s]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < m; i++)
        {
            if (ind[i] == 0) q.push(i);
        }
        vector<int> res;
        while (!q.empty())
        {
            int t = q.front(); q.pop();
            res.push_back(t);
            for (int i = 0; i < G[t].size(); i++)
            {
                int s = G[t][i]; ind[s]--;
                if (ind[s] == 0) q.push(s);
            }
        }
        if (res.size() != m) return vector<int>();
        return res;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
    {
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1) group[i] = m++;
        }
        vector<unordered_set<int>> gvc(m, unordered_set<int>());
        for (int i = 0; i < n; i++)
        {
            gvc[group[i]].insert(i);
        }
        vector<vector<int>> among(m, vector<int>()), within(n, vector<int>());
        for (int i = 0; i < beforeItems.size(); i++)
        {
            for (int j = 0; j < beforeItems[i].size(); j++)
            {
                int t = beforeItems[i][j];
                int x = group[i], y = group[t];
                if (x != y) among[y].push_back(x);
                else within[t].push_back(i);
            }
        }
        vector<int> tmp = toposort_group(among);
        if (tmp.empty()) return tmp;
        vector<int> res = toposort_item(tmp, gvc, within);
        return res;
    }
};