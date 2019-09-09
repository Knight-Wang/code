class Solution
{
public:
    vector<int> p;
    void init(int n)
    {
        p.resize(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i;
    }
    int find(int x)
    {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool uni(int x, int y)
    {
        x = find(x); y = find(y);
        if (x == y) return false;
        p[x] = y; return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = 0;
        for (auto it: edges)
        {
            n = max(n, max(it[0], it[1]));
        }
        init(n);
        vector<int> res;
        for (auto it: edges)
        {
            int x = it[0], y = it[1];
            if (!uni(x, y)) res = it;
        }
        return res;
    }
};